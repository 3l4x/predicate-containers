# Predicate Containers

An assignment I had in 2021 with C++. My solution is in predconts.h, main.cpp is used to test whether my solution is ready for submission or not. I got the original task in Hungarian so the translation might not be the most accurate. To be fair the Hungarian description was overcomplicated for no reason.


## English description of my task
The predicate_containers is a template class where, based on the type of the first template parameter, we store the elements in two sequential containers according to a predicate (whose type is the second template parameter). In the last few checks:

- The constructor receives the two sequential containers, which, regardless of their previous content, become empty, and we insert the elements using the insert member function: if the element is true according to the predicate, it goes into the first container, otherwise into the second, at any position. In the constructor, we also provide the predicate object so that stateful functors can be used. If the predicate is not provided as a constructor parameter, it should be default-constructed.
- The erase member function deletes all occurrences of the element passed as a parameter.
- The insert member function that expects an interval adds all elements of the interval to the appropriate container.
- The += operator adds the elements handled by the right-hand operand to the containers managed by the left-hand operand, according to the predicate of the left-hand operand.

## Hungarian equivalent

A predicate_containers egy olyan template osztály, ahol az első template paraméter típusának megfelelő két
szekvenciális konténerbe egy predikátum (aminek típusa a második template paraméter) szerint tároljuk el az elemeket. Az utolsó néhány ellenőrzésnél :

- Konstruktorban megkapja a két szekvenciális konténert, amelyeknek bármi is volt is tartalmuk, üressé válva insert tagfüggvénnyel adunk elemeket: ha az elem a predikátum szerint igaz, akkor az első konténerbe, különben a
másodikba kerül, tetszőleges pozicióra.  A konstruktorban a predikátum objektumot is megadom, hogy állapottal rendelkező funktorokat is lehessen használni. Ha a predikátum nincs megadva konstruktor paraméterként, akkor
default konstruálni kell.
- Az erase a paraméterként megkapott elem összes előfordulását törli.
- Az intervallumot váró insert az intervallum összes elemét hozzáadja a megfelelő konténerhez. A += operátor a baloldali objektum által kezelt konténerekhez hozzáadja a jobb oldali operandus által kezelt elemeket a baloldali operandus predikátuma szerint a megfelelő konténerekhez.

