#pragma once

#include <map>

//Proxy создает двумерный доступ через matrix[x][y] как в обычном массиве.

// T - тип элементов матрицы, DefaultValue - значение, которое не занимает ячейку
template <typename T, T DefaultValue>
class Matrix {
protected:
	std::map<std::pair<int, int>, T> elements; // ключ - координаты ячейки x y, значение - содержимое ячейки
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
	
    // Proxy-объект для ячейки, ячейка создается только при записи значения, отличного от DefaultValue.
	class CellProxy{
	    Matrix& matrix;
	    int x, y;
	public: 
	    //Конструктор хранит ссылку на матрицу и координаты
	    CellProxy(Matrix& m, int xi, int yj) : matrix(m), x(xi), y(yj) {}
        // Оператор ищет ячейку в map, возвращает найденное или дефолтное значение 
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
		    else // если ячейка не была занята - увеличиваем счетчик
		    { 
		      if (matrix.elements.count(key) == 0) 
		      { 
		        matrix.elements[key] = value;
		        matrix.cell_count++;
		      }
		      else // а если она была занята - перезаписываем значение тк на этот счет нет никаких указаний в т/з
		      {
		        matrix.elements[key] = value;
		      }
		    }
		    return *this;
		}
	};
	
    // Нужен для цепочки вызовов matrix[x][y]
	class RowProxy {
	    Matrix& matrix;
	    int x;
	    public:
	        // Хранит ссылку на оригинальную матрицу и номер строки
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



