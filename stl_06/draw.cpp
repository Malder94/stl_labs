//region Task
/*
 *    Написать программу, которая выполняет следующие действия (все операции должны выполняться
 *    с помощью стандартных алгоритмов):
 *      a. Заполняет вектор геометрическими фигурами. Геометрическая фигура может быть треугольником,
 *         квадратом, прямоугольником или пяти угольником. Структура описывающая геометрическую
 *         фигуру  определена ниже
 *      b. Подсчитывает общее количество вершин всех фигур содержащихся в векторе (так треугольник
 *         добавляет к общему числу 3, квадрат 4 и т.д.)
 *      c. Подсчитывает количество треугольников, квадратов и прямоугольников в векторе
 *      d. Удаляет все пятиугольники
 *      e. На основании этого вектора создает vector<Point>, который содержит координаты одной из
 *         вершин (любой) каждой фигуры, т.е. первый элемент этого вектора содержит координаты
 *         одной из вершину первой фигуры, второй элемент этого вектора содержит координаты одной
 *         из вершину второй фигуры и т.д.
 *      f. Изменяет вектор так, чтобы он содержал в начале все треугольники, потом все квадраты,
 *         а потом прямоугольники.
 *      g. Распечатывает вектор после каждого этапа работы
 *
 * Геометрическая фигура задается следующей структурой:
 * typedef  struct
 * {
 *   int vertex_num;      // количество вершин, для треугольника 3, для квадрата и
 *                                  // прямоугольника 4, для пяти угольника 5
 *   vector<Point> vertexes;   // вектор содержащий координаты вершин фигуры
 *   // Для треугольника содержит 3 элемента
 *				    // Для квадрата и прямоугольника содержит 4
 *                                            // элемента
 *                                            // Для пятиугольника 5 элементов
 * } Shape;
 *
 * typedef struct
 * {
 *   int x,y;
 * } Point;
 *
 *
 * Подсказка: кроме алгоритмов рассмотренных в этой работе можно применять все средства описанные
 * в предыдущих работах, включая алгоритмы сортировки.
*/
//endregion Task

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    int x,y;
} Point;

typedef  struct
{
    int vertex_num;
    vector<Point> vertexes;
} Shape;

Point MakeTriangle(vector<Point>& vertexes)
{
    Point point1 {0, 0};
    Point point2 {7, 0};
    Point point3 {4, 4};

    vertexes.push_back(point1);
    vertexes.push_back(point2);
    vertexes.push_back(point3);
}

Point MakeSquareOrRectangle(vector<Point>& vertexes)
{
    int rX = rand() % 2;

    Point point1 {0, 0};
    Point point2 {5 + rX, 0};
    Point point3 {0, 5};
    Point point4 {5 + rX, 5};


    vertexes.push_back(point1);
    vertexes.push_back(point2);
    vertexes.push_back(point3);
    vertexes.push_back(point4);
}

Point MakePentagon(vector<Point>& vertexes)
{
    Point point1 {0, 0};
    Point point2 {5, 0};
    Point point3 {0, 6};
    Point point4 {6, 0};
    Point point5 {4, 6};


    vertexes.push_back(point1);
    vertexes.push_back(point2);
    vertexes.push_back(point3);
    vertexes.push_back(point4);
    vertexes.push_back(point5);
}

Shape NewShape(int vertex_num)
{
    Shape newShape;
    newShape.vertex_num = vertex_num;

    switch (vertex_num)
    {
        case 3 :
            MakeTriangle(newShape.vertexes);
            return newShape;
        case 4 :
            MakeSquareOrRectangle(newShape.vertexes);
            return newShape;
        case 5 :
            MakePentagon(newShape.vertexes);
            return newShape;
        default:
            cout << "I can't work with that!" << endl;
            break;
    }
}

void PrintShape(vector<Shape>& v)
{
    for (auto& i : v)
        cout << i.vertex_num << " " << i.vertexes[3].x << " " << i.vertexes[3].y << endl;
}

void SumVertexes(const vector<Shape>& v)
{
    int sumVertexes = 0;

    for (auto i : v)
        sumVertexes += i.vertexes.size();

    cout << "Vertex sum: " << sumVertexes << endl;

}

void ShapesCount(const vector<Shape>& v)
{
    auto first = v.begin();
    auto last = v.end();

    vector<int> counts;
    int s = 0;

    for (int points = 3; points <= 5; ++points)
        counts.push_back(count_if(first, last, [points](const Shape& sh) -> bool {
            return sh.vertex_num == points;
        }));

    cout << "\nNumber of shapes:\n";

    cout << "Triangles: "  << count_if(first, last, [](const Shape& sh) -> bool {
        return sh.vertex_num == 3
        ;})  << endl;
    cout << "Rectangles: " << count_if(first, last, [](const Shape& sh) -> bool {
        return (sh.vertex_num == 4) && (sh.vertexes[3].x != sh.vertexes[3].y)
                ;})  << endl;
    cout << "Squares: "    << count_if(first, last, [](const Shape& sh) -> bool {
        return (sh.vertex_num == 4) && (sh.vertexes[3].x == sh.vertexes[3].y)
                ;})  << endl;
    cout << "Pentagons:"   << count_if(first, last, [](const Shape& sh) -> bool {
        return sh.vertex_num == 5
                ;})  << endl;
}

void ErasePentagons(vector<Shape>& v)
{
    vector<Shape>::iterator removedRange = remove_if(v.begin(), v.end(), []( Shape& sh) -> bool {
            return sh.vertex_num == 5;
    });

    v.erase(removedRange, v.end());
}

void CreatePoints(vector<Shape>& shapes, vector<Point>& points)
{
    for (auto shape : shapes)
        points.push_back(shape.vertexes[rand ()% shape.vertexes.size()]);
}

void PrintPoints(const vector<Point>& points)
{
    cout << "Points: \n";

    for (auto point : points)
        cout << point.x << " " << point.y << endl;
}

void SortShapes(vector<Shape>& v)
{
    auto first = v.begin();
    auto last = v.end();

    sort(first, last, [](Shape& sh1, Shape& sh2){
        if (sh1.vertex_num != sh2.vertex_num)
            return sh1.vertex_num < sh2.vertex_num;
        else if (sh1.vertex_num != 4)
            return sh1.vertex_num < sh2.vertex_num;
        else
        {
            if (sh1.vertexes[3].x == sh1.vertexes[3].y)
                return true;
            else
                return false;
        }
    });
}

int main()
{
    vector<Shape> shapes;
    vector<Point> points;

    for (int i = 100; i > 0; --i)
        shapes.push_back(NewShape(rand() % 3 + 3));

    SortShapes(shapes);

    PrintShape(shapes);

    SumVertexes(shapes);

    ShapesCount(shapes);

    ErasePentagons(shapes);

    ShapesCount(shapes);

    CreatePoints(shapes, points);

    PrintPoints(points);

}