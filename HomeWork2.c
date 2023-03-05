#include <stdio.h>
#include <ctype.h>
//Домашнее задание. 2-ой семинар
void remove_spaces(char* str);//1-е задание
void print_words(char* str);//2-е задание
void print_repeating_chars(char* str);//3-е задание


int main() {                
    char str[1000];          
    char str2[1000];              
    char str3[1000];
    printf("ENTER THE TEXT: ");          
    fgets(str, 1000, stdin);               

    remove_spaces(str);                    
    printf("TEXT WITHOUT SPACES AND TABS IS:\n%s\n", str);                

    printf("ENTER THE TEXT: ");              
    fgets(str2, 1000, stdin);               

    printf("A WORD WITH A NEW STRING:");        
    print_words(str2);        

    printf("ENTER THE TEXT: ");        
    fgets(str3, 1000, stdin);            

    print_repeating_chars(str3);             

    return 0;      
}
void remove_spaces(char* str) {        //удаляет все пробелы,табуляции и пустые строки
    char* read_ptr = str;         //указатель. Проходит по строке str 
    char* write_ptr = str;           //указатель. Записывает символы из read_ptr в str 
    int in_space = 0;               //переменная-счётчик(флаг)

    while (*read_ptr) {              //цикл, в котором мы проверяем каждый символ на ' ' и табуляцию, заменяя всё на один 
        if (isspace(*read_ptr)) {    //' ' или нет? 
            if (!in_space) {       
                in_space = 1;        //Флаг равен единице(значение)
                *write_ptr++ = ' ';  //Пропускаем
            }
        }
        else {                       //иначе
            in_space = 0;            //Флаг равен 0 
            *write_ptr++ = *read_ptr; //Символ записываем в строку
        }
        ++read_ptr;   //переключаемся на седующий символ 
    }
    if (in_space && write_ptr > str) {   //ищм этот пробел
        --write_ptr;   //удаляем
    }
    *write_ptr = '\0';    //завершаем строку

    // Удаление пустых строк
    read_ptr = str;  //всё то же самое
    write_ptr = str;     //всё то же самое
    int newline = 1;    //всё то же самое, только флаг в обратную сторону(проверяет, являласьли предыдущая строка пустой)

    while (*read_ptr) {   //проходимся по элементам 
        if (*read_ptr == ' ') {      //пробел 
            ++read_ptr;    //переходим к следующему символу
        }
        else if (*read_ptr == '\t') {     //табуляция
            ++read_ptr;     //1-е задание
        }
        else if (*read_ptr == '\n') {     //символ новой строки
            if (newline) {     //счётчик равна единице
                ++read_ptr;      //пропускаем
            }
            else {           //иначе
                newline = 1;       //счётчик равен нулю 
                *write_ptr++ = *read_ptr++;      //помещаем сивол в строку без пустых строк
            }
        }
        else {          //что-то есть
            newline = 0;       //непустая строка
            *write_ptr++ = *read_ptr++;        //помещаем в строку без пустых строк
        }
    }
    if (write_ptr > str && *(write_ptr - 1) == '\n') {   //были ли в конце строки пробелы и переводы строки на новую строку
        --write_ptr;    //если да, то удаляем
    }
    *write_ptr = '\0';  //устанавливаем нулевой символ, чтобы закончить строку
}

void print_words(char* str) {    //2-е задание
    while (*str) { //проходимся по строке, пока не достигнут конец строки
        while (isspace(*str)) { //пропускаем все пробельные символы
            ++str;
        }
        if (*str) {  //если строка не закончилась, то выводим слово
            char* word_start = str; //указатель на начало слова
            while (*str && !isspace(*str)) { //пока не достигнут конец строки или разделитель
                ++str;
            }
            putchar('\n'); //пока не достигнут конец строки или разделитель
            while (word_start < str) { //выводим слово
                putchar(*word_start++); //выводим символ новой строки, чтобы перейти на следующую строку
            }
        }
    }
    putchar('\n'); //выводим последний символ новой строки
}

void print_repeating_chars(char* str) {      //3-е задание
    int len = strlen(str); //длина входной строки
    int count = 1; 
    for (int i = 1; i < len; i++) { //перебираем все символы, начиная со второго
        if (str[i] == str[i - 1]) { //сравниваем символ с предыдущим
            count++; //если равны, то увеличиваем счётчик на 1
        }
        else {
            if (count >= 3) { //если нет, то проверяем, сколько раз подряд встречался символ(достаточно ли длинная)
                for (int j = i - count; j < i; j++) {
                    printf("%c", str[j]);
                }
                printf("\n");
            }
            count = 1;
        }
    }
    // можно реализовать проверку на повторение последних символов в строке
    if (count >= 3) {
        for (int j = len - count; j < len; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}
