## LinkedList
### 1.
Написать метод `removeAlternating` структуры `LinkedIntList`, 
который чередует удаление узла из каждой пары узлов в списке. 

В первой паре должно быть удалено первое число, во второй – второе. 

В третьей паре он возвращается к первому удаляемому номеру, 
далее повторяется для следующих пар. 
Если список имеет нечетную длину, последнее значение не удаляется, 
поскольку оно не является частью пары. 

Значения, удаленные из списка, 
должны быть возвращены методом в новом `LinkedIntList`, 
причем значения заданы в том же порядке, что и исходный список. 

Пример выполнения программы:
```
// list1: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

[1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11]
 |   |   |   |   |   |   |   |   |    |
 +---+   +---+   +---+   +---+   +----+
 pair1   pair2   pair3   pair4   pair5

LinkedIntList *list2 = list.removeAlternating();
// list1: [2, 3, 6, 7, 10, 11]; list2: [1, 4, 5, 8, 9]
```

Ограничения: 
- Вы можете добавить приватные, вспомогательные методы, однако вы не можете предполагать, что какие-либо конкретные методы доступны. 
- Вам разрешено определять свои собственные переменные типа `Node`, но вы не можете создавать какие-либо новые узлы.
- Также вы НЕ МОЖЕТЕ использовать вспомогательные структуры данных (массив, `vector`, `string` и т. д.). 
- Вы также не можете изменять какие-либо поля данных узлов. Вы ДОЛЖНЫ решить эту проблему, переставив ссылки в списке. 
- Ваше решение должно выполняться за время O (n), где n - длина списка.

### 2.
Реализовать алгоритм quickSort для структуры `LinkedIntList`.

```c++
int compare (Node *a, Node *b) {

}

void swap(int *a, int *b) {

}

int partition(LinkedIntList *pList, int left, int right) {
    Node *pivot;
}

void quickSort(LinkedIntList *pList, int left, int right) {

}
```