#pragma once

#include <map>


template <typename T, T DefaultValue>
class Matrix {
protected:
	std::map<std::pair<int, int>, T> elements;
	size_t cell_count; // Количество занятых ячеек (не занятые не считаем и не храним). 
public:
	Matrix() {
	   cell_count = 0;
	};	

	~Matrix() = default;

	size_t size() const
	{
	    return cell_count;
	}
	
        // Proxy-объект для ячейки
	class CellProxy{
		Matrix& matrix;
		int x, y;
		public: 
		    CellProxy(Matrix& m, int xi, int yj) : matrix(m), x(xi), y(yj) {}
	
	    operator T() const {
            auto it = matrix.elements.find({x, y});
            return it != matrix.elements.end() ? it->second : DefaultValue;
        }
	

        
	// Оператор присваивания = запись в ячейку
	CellProxy& operator=(const T& value)
	{
	    std::pair<int, int> key{x, y};
            // Значение по умолчанию должно освобождать ячейку
	    if (value == DefaultValue)
	    {
	        if (matrix.elements.count(key) == 1){
		    matrix.elements.erase(key);
	            matrix.cell_count--;        
	        }

	    }
	    else 
	    { // если ячейка не была занята - увеличиваем счетчик
	      if (matrix.elements.count(key) == 0) 
	      { 
	        matrix.elements[key] = value;
	        matrix.cell_count++;
	      }
	      else
	      {
	        matrix.elements[key] = value;
	      }
	    }
	
	    return *this;
	}
	};
	

	class RowProxy {
		Matrix& matrix;
		int x;
		public:
		    RowProxy(Matrix& m, int xi) : matrix(m), x(xi) {};

                // Обращение к ячейке в строке
		CellProxy operator[](int y)
		{
		    return CellProxy(matrix, x, y);
		}
	};

       // оператор для доступа к строке
          RowProxy operator[](int x) {
              return RowProxy(*this, x);
          }
          
      // Итераторы
       auto begin() { return elements.begin(); }
       auto end() { return elements.end(); }

};

