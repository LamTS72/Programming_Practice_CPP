#include <iostream>
//#include<cstring>
#include<fstream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

/*//============================LAB_1==================================
void process(char str[], char outstr[]){
    size_t length = strlen(str);
    int i = 0;
    int j = -1;
    //remove heading space
    while (++j < length && str[j] == ' ');
    for(;j<length;j++){
        if(str[j] == ' '){
            if(str[j-1]== ' '){
                continue;
            }
        }
        outstr[i++] = str[j];
    }
    //remove tailing space
    while(i-- >0 && outstr[i] == ' ' );
    outstr[i+1] = '\0';

}
void process(const char *str, char *outstr) {
    // TODO
    size_t n = strlen(str);
   // outstr[n + 1];
    if (outstr != NULL)
    {
        outstr +=n;
        *outstr = '\0';
        
        while (*str) {
            *--outstr = *str++;
        }
    }
}
int calc(char str[]){
    int result = 0;
    int base = 1;
    size_t length = strlen(str);
    for(size_t i = length - 1; i >= 0;i--){
        if(str[i] == '1'){
            result += base;
        }
        base = base * 2;
    }
    return result;
}

void calSum(string fileName)   {
    // TODO
    ifstream myFile;  // declare a file

    myFile.open(fileName); // open the file
    int sum = 0;
    int num;
    while ((myFile >> num) )  //reading a line from the file while possible
    {
        
        sum = sum + num;    // convert string to number and add it to the sum
    }

    myFile.close();   // closing the file
    cout<<sum;
}
 
int findMaxColumn(int arr[][1000], int row, int col) {
    int index;
    int flag = 0;
    int max = 0;
    for(int j = 0; j < col; j++){
        int sum = 0;
        for(int i = 0;i< row; i++){
            sum += arr[i][j];
        }
        if(sum > max){
            max = sum;
            flag = j;
        }
    }
    index = flag;
    return index;
}

int diagonalProduct(int arr[][1000], int row, int col) {
    int product = 1;
    for(int i = 0;i < row;i++){
        product *= arr[i][i];
    }
    return product;
}

bool isSymmetric(int arr[][1000], int row, int col) {
    for(int i = 0;i < row; i++){
        for( int j = 0 ;j< col;j++){
            if(arr[i][j] != arr[j][i]){
                return false;
            }
        }
    }
    return true;
}

//55 85 47 58        { 88,72,65,37},;
//31 04 60 67         {82,84,34,12}
//94 69 71 73         {74,46,88,44}}
//51 62 64 90
int diagonalDiff(int arr[][1000], int row, int col, int x, int y) {
    int result;
    int result1; int result2;
    int temp1 = 0;int temp2 = 0;
    int temp3 = 0;int temp4 = 0;
    int i=x;int j = x;
    int z=y;int t = y;
    
    int a=x;int b = x;
    int c=y;int d = y;
    
    while(i<row ){
        if(z < col){
            temp1 += arr[i][z];
            z++;
         //   cout<<temp1<<" ";
        }
        i++;
    }
   // cout<<endl;
    while(j >= 0){
        if(t >= 0){
            temp2 += arr[j][t];
            t--;
          //  cout<<temp2<<" ";
        }
        j--;
    }
    result1 = temp1 + temp2 - arr[x][y] ;
   // cout<<result1<<" ";
    while(a>=0 ){
        if(c < col){
            temp3 += arr[a][c];
            c++;
        }
        a--;
    }
    while(b < row){
        if(d >= 0){
            temp4 += arr[b][d];
            d--;
        }
        b++;
    }

    result2 = temp3 + temp4 - arr[x][y];
  //  cout<<result2<<" ";
    result = result1 - result2;
    if(result < 0){
        return -result;
    }
    return result;
}


void uppercase(string output)   {
    // TODO
//    string temp;
//    getline(cin,temp);
//
//    fstream myFile;
//
//    //long n = temp.length();
//    //cout<<n;
// //   string temp;
//
//    for(int i = 0;i<temp.length();i++){
//        if(temp[i] >= 'a' && temp[i] <= 'z'){
//            temp[i] = temp[i] - 32;
//        }
//    }
//    string words = temp;
//    myFile.open(output);
//    if(myFile.is_open()){
//        cout<<"error";
//    }
//    myFile << words;
//    //cout << ;
//    myFile.close();
    string temp;
    getline(cin,temp);
    for(int i =0 ; i < temp.length();i++){
        if('a' <= temp[i] && temp[i] <= 'z'){
            temp[i] -= 32;
        }
    }
    ofstream myFile;
    myFile.open(output);
    myFile << temp;
    myFile.close();


}

void threeChars(string fileName)   {
    // TODO
    ifstream myFile;
    myFile.open(fileName);
    string line;
    while(getline(myFile, line)){
        string temp = line;
        if(temp[0] <= temp[1] && temp[1] <= temp[2]){
            if(temp == "***"){
                break;
            }
            cout<<"true"<<endl;
            
        }
        else{
            cout<<"false"<<endl;
        }

    }
         
}
void process3(string fileName)   {
    // TODO
    ifstream myFile;
    myFile.open(fileName);
    string line;
    getline(myFile,line);
    string temp = line;
    int row = int(temp[0]) - '0';
    int col = int(temp[2]) - '0';
    int number = row * col;
    double temp_arr[number];
    double arr[row][col];
    int i = 0;
    double num;
    while(!myFile.eof()){
        myFile >> num;
        temp_arr[i] = num;
        i++;
    }
    i = 0;
    for(int k = 0; k < row;k++){
        for(int j = 0; j < col;j++){
            arr[k][j] = temp_arr[i++];
        }
    }
    double max_total = arr[0][0];
    for(int s = 0; s < row;s++){
        double max2 = arr[s][0];
        for(int r = 1; r < col;r++){
            if(arr[s][r] >= max2){
                max2 = arr[s][r];
            }
            if(arr[s][r] >= max_total){
                max_total = arr[s][r];
            }
        }
        cout<<max2<<" ";
    }
    cout<<max_total;
    myFile.close();
}


long factorial_cal(int n){
    if(n < 0){
        return -1;
    }
    else if(n == 0){
        return 1;
    }
    else
        return n*factorial_cal(n-1);
}

int findMax(int *vals, int numEls) {
    // TODO
    int max = vals[0];
    for(int i = 1; i<numEls;i++){
        if(vals[i] >= max){
            max = vals[i];
        }
    }
    return max;
}

void sum2(int * array, int numEls, int &result)
{
    // TODO
    int res = 0;
    for(int i = 0; i < numEls ; i++){
        res += array[i];
    }
    result = res;
}

bool completeNum(int N)
{
    // TODO
    if(N<=0) return false;
    int sum = 0;
    for(int i = 1; i < N; i++){
        if(N%i == 0){
            sum+= i;
        }
    }
    if(sum == N){
        return true;
    }
    return false;
}

void cutString(string s, int index){
    // TO DO
    if(index >= s.length() || index < 0){
        return;
    }
    cout<<s.substr(index,s.length());
    cout<<s.length();
}

void findAllIndex(string s1, string s2){
    // TO DO
    bool flag = false;
    bool check = false;
    for (int i = 0; i < s1.length(); i++) {
        if (s1.substr(i,s2.length()).find(s2) != -1) {
            if(check == true){
                flag = true;
                cout<<" "<<i;
            }
            else{
                flag = true;
                cout<<i;
                check = true;
            }
        }
    }
 
    if (flag == false)
        cout<<-1;
}

void process1(const char *name, char *outstr) {
    // TODO
    size_t length = strlen(name);
    int i = 0;
    int j = -1;
    bool flag_upper = true;
    while(++j < length && name[j] == ' ');
    while(j < length ){
        if((name[j] >= 'a' && name[j] <= 'z') ||
           (name[j] >= 'A' && name[j] <= 'Z') ){
            if(flag_upper){
                if(name[j] >= 'a' && name[j] <= 'z'){
                    outstr[i] = name[j] - 32;
                }
                else{
                    outstr[i] = name[j];
                }
                flag_upper = false;
            }
            else{
                if(name[j] >= 'A' && name[j] <= 'Z'){
                    outstr[i] = name[j] + 32;
                }
                else{
                    outstr[i] = name[j];
                }
            }
            j++;
            i++;

        }
        else if(name[j] == ' '){
            while(!((name[j+1] >= 'a' && name[j+1] <= 'z') ||
               (name[j+1] >= 'A' && name[j+1] <= 'Z')   )){
                j++;
            //    i++;
            }if((name[j+1] >= 'a' && name[j+1] <= 'z') ||
                (name[j+1] >= 'A' && name[j+1] <= 'Z')){
                j++;
            }
            else{
                outstr[i] = ' ';
                i++;
            }
            j++;
            i++;
            flag_upper = true;
        }
        else{
            j++;
          //  cout<<j<<endl;
        }

    }
    while(i-- >0 && outstr[i] == ' ' );
    outstr[i+1] = '\0';
    
}

void printFirstRepeatedWord(char str[]) {
    // TODO
    char temp[100][100] = {};
    int count_word = 0;
    int i = 0;
    while (str[i] != 0) {
        int begin = 0;
        while(str[i] != 0 && str[i] != ' '){
            temp[count_word][begin] = str[i];
            i++;
            begin++;
        }
        temp[count_word][begin] = 0;
        count_word++;
        if(str[i] == ' '){
            i++;
        }
    }
    for(int i = 0; i < count_word; i++){
        cout<<temp[i]<<"\n";
    }
   // bool found = false;
    for ( int i = 0; i < count_word ; i++){
        for(int j = i +1 ; j < count_word; j++){
            int i1 = 0; int j1 = 0;
            while(temp[i][i1] != 0 && temp[j][j1] != 0){
                if(temp[i][j1] != temp[j][j1]){
                    break;
                }
                i1++;
                j1++;
            }
            if(temp[i][i1] == 0 && temp[j][j1] == 0){
                cout<<temp[i];
                return;
            }

        }
    }
    cout<<"No Repeation";
    
}

int ascendingRows(int arr[][1000], int row, int col) {
    int result = 0;
    bool check = false;
    for(int i = 0 ; i < row ; i++){
        for(int j = 1 ; j< col; j++){
            if(arr[i][j] < arr[i][j-1]){
                check = true;
                break;
            }
        }
        if(check){
            check = false;
        }
        else{
            result++;
        }
        
    }
    return result;
}

bool isPrime(int n){
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int primeColumns(int arr[][1000], int row, int col) {
    int result = 0;
    for(int j = 0 ; j< col; j++){
        int sum = 0;
        for(int i = 0; i< row; i++){
            sum += arr[i][j];
        }
        if(isPrime(sum)){
            result++;
        }
    }
    return result;
}

bool isPalindrome(const char* str) {
    // Write your code here
    //size_t length = strlen(str);
    int length = 0;
    int i = 0;
    while(str[i] != 0){
        ++length;
        i++;
    }
  //  cout << length;
    for(int i = 0; i < length;i++){
        if(str[i] != str[length-i-1]){
            return false;
        }
    }
    return true;
}
bool isSpecialNumber(int n) {
    // Write your code
     
    int temp = n;
    int sum = 0;
    while(temp != 0){
        sum += temp%10;
        temp = temp/10;
    }
    if(isPrime(sum)){
        return true;
    }
    return false;
}

bool checkElementsUniqueness(int* arr, int n) {
    // Write your code
    if(n <= 0) return false;
    for(int i = 0;i<n;i++){
        for( int j = i+1;j<n;j++){
            if(arr[i] == arr[j]){
                return false;
            }
        }
    }
    return true;
}

long int decimalToBinary(int decimal_number)
{
//    int base = 1;
//    long int sum = 0;
//    //int temp = ;
//    while(decimal_number != 0){
//        sum += (decimal_number%2)*base;
//        base = base * 10;
//        decimal_number = decimal_number/2;
//    }
//    return sum;
    if (decimal_number == 0)
           return 0;
       else
           return (decimal_number % 2 + 10 *
                   decimalToBinary(decimal_number / 2));
}

void encrypt(char* text, int shift) {
    while(shift < 0){
        shift += 26;
    }
        for(int i = 0; text[i] != '\0';i++){
            if(text[i] >= 'a' && text[i] <= 'z'){
                text[i] = char(int(text[i] + shift - 97) % 26 + 97);
            }
            if(text[i] >= 'A' && text[i] <= 'Z'){
                text[i] = char(int(text[i] + shift - 65) % 26 + 65);
            }
        }

}

void decrypt(char* text, int shift) {
    // Write your code
    encrypt(text,-shift) ;
    
}
void replaceString(string s, string s1, string s2){
    //TO DO
    int i = 0;
    int index = -1;
    while(i < s.length()){
        if (s.substr(i,s1.length()).find(s1) != -1) {
            index = i;
        }
        i++;
    }
    string str;
    if(index != -1){
        str = s.replace(index, s1.size(),s2);
    }
    else{
        str = s;
    }
    cout<<str;
}

void deleteWord(string s, string s1){
    //TO DO
//    int i = 0;
//    int index = -1;
//    while(i < s.length()){
//        if (s.substr(i,s1.length()).find(s1) != -1) {
//
//        }
//        i++;
//    }
//    string str;
//    while(s.size()!=0&&s.find(s1)<s.size()){
//        str = s.erase(s.find(s1),s1.size());
//    }
//    cout << str;
//    size_t n = s.length();
//    size_t k = s1.length();
//
//     string t(n, ' ');
//     int j = 0;  // t's index
//
//     for (int i = 0; i < n; ++i) {
//       t[j++] = s[i];
//       if (j >= k && t.substr(j - k, k) == s1)
//         j -= k;
//     }
//    cout << t.substr(0, j);
    string str;
        auto f = s.find(s1);//find method return the heading position which is the same original string.
            while (f != string::npos) {
                s.erase(f, s1.size());
                f = s.find(s1);
            }
    str = s;
    cout << str;
    
}
//============================LAB_1================================== */
//int main(int argc, const char * argv[]) { //FOR LAB 1
    //    string name = "/Users/chessman/Desktop/Xcode/example_cpp/example_cpp/test.txt";
    //    calSum(name);
    //    int arr[][1000] = {{-44,64,-6},{87,92,-19},{-92,53,-38},{-39,-92,21}};
    //    cout << findMaxColumn(arr, 4, 3);
    //    int arr[][1000] = {{-92,78,-2,-58,-37},{44,-4,30,-69,22}};
    //    cout << findMaxColumn(arr, 2,5);
    //    int arr[][1000] = {{-45,18,-37},{-2,-31,24},{-48,-33,-48}};
    //    cout << diagonalProduct(arr,3,3);
//        string words;
//        cin >> words;
//        int max = 0;
//        int length = 0;
//        int i = 0;
//        //cout<<words.length();
//        while(i < words.length()){
//            if(words[i] != words[i-1]){
//                length = 0;
//            }
//            ++length;
//            if(length > max){
//                max = length;
//            }
//            i++;
//        }
//        cout<<max;
    //    int arr[][1000] = {{1,9,6}, {4,5,3}, {6,3,9}};
    //    cout << isSymmetric(arr,3,3);
    //chi
//        int arr[][1000] = {{55,85,47,58},{31,4,60,67},{94,69,71,73},{51,62,64,90}};
//        cout << diagonalDiff(arr,4,4,1,2);
//        int arr[][1000] = {{88,72,65,37},{82,84,34,12},{74,46,88,44}};
//        cout << diagonalDiff(arr,3,4,1,0);
    //    return 0;
    //    int N; cin >> N;
    //    cout<<completeNum(N);
    //88,72,65,37
    //82,84,34,12
    //74,46,88,44
    //
    //    string s = "Truong Dai Hoc Bach Khoa.";
    //    cutString(s, 1);
    
    //    string s1 = "Truong Dai Hoc Bach Khoa.";
    //    string s2 = "a";
    //    findAllIndex(s1, s2);
    
   // const int MAX_SIZE = 100;
//    char str[] = "  !  doAn      VAN   *((   )hau @!#$     " ;
//    char outstr[100];
//    process1(str, outstr);
//    cout << outstr;
//    cout<<"|";
//    char str[] = "car taxi bike bike car taxi" ;
//    printFirstRepeatedWord(str);
//    int arr[][1000] = {{32,4,9},{-80,37,71},{-91,-79,-55}};
//    cout << ascendingRows(arr,3, 3);
//    int arr[][1000] = {{-28,-8,-60,18},{-100,44,-1,24},{-94,92,-70,75}};
//    cout << ascendingRows(arr,3,4);
//    int arr[][1000] = {{-64,-28,-3,64},{-56,90,57,-31}};
//    cout << primeColumns(arr,2,4);
//    int arr[][1000] = {{34,-15,11,-70,-23,24},{-39,-90,63,-45,-52,48},{-42,92,55,92,82,81}};
//    cout << primeColumns(arr,3,6);
//    const char* str = "abba";
//    cout << isPalindrome(str);
//    const char* str = "axz";
//    cout << isPalindrome(str);
//    int n;
//    cin >> n;
//    cout << isSpecialNumber(n);
//    int n;
//    cin >> n;
//    int* arr = new int[n];
//    for(int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//    cout << checkElementsUniqueness(arr, n);
//    delete[] arr;
   // cout << decimalToBinary(20);
    //cout << decimalToBinary(192);
    
//    int n, shift;
//    cin >> n >> shift;
//    char* text = new char[n+1];
//    for(int i = 0; i < n; i++) cin >> text[i];
//    text[n] = 0;
//
//    encrypt(text, shift);
//    cout << text << '\n';
//    decrypt(text, shift);
//    cout << text;
//
//    delete[] text;
 //   string name = "/Users/chessman/Desktop/Xcode/example_cpp/example_cpp/test.txt";
    //threeChars(name);
 //   process3(name);
//    string s = "Truong Dai Hoc Bach Khoa, Sai Gon";
//    string s1 = "ai";
//    string s2 = "ong";
//    replaceString(s, s1, s2);
//    string s = "Truong Dai Hoc Bach Khoa, Sai Gon";
//    string s1 = "ai ";
//    deleteWord(s, s1);
    
//}

/*//============================LAB_2==================================
//RECURSION_PRELAB
int gcdRecursion(int p, int q){
    if(p==0 || q==0 )
        return p+q;
    if(p==q)
        return p;
    if(p>q)
        return gcdRecursion(p-q,q);
    else return gcdRecursion(p,q-p);
}
int gcdIteration(int p, int q)
{
   // if(p == 0 && q == 0) return 0;
    if (p == 0 || q == 0){
            return p + q;
        }
    while (p != q){
            if (p > q){
                p -= q;
            }else{
                q -= p;
            }
        }
        return p;
}
int strLen(char* str)
{
    if (*str == '\0')
        return 0;
    else
        return 1 + strLen(str + 1);
}
void printPattern(int n)
{
    int temp = 5;
    if(n <= 0){
        temp = -temp;
        cout <<n;
        return;
    }
    else{
        //if(n - temp > 0)
        cout << n <<",";
        //else cout << n;
        printPattern(n - temp);
    }
    
    cout <<"," <<n;

}
//POINTER BASIC_PRELAB
int getValueAtIndex(int *ptr, int k)
{
    int idx = 0;
    while(ptr != NULL){
        if(idx == k){
            return *ptr;
        }
        idx++;
        ++ptr;
    }
    return -1;
}
void swap(int *ptr1, int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int* zeros(int n) {
    if(n <= 0) return nullptr;
    int *array = new int[n];
    for(int i= 0; i < n ;i++){
        array[i] = 0;
    }
    return array;
}
void shallowCopy(int*& newArr, int*& arr) {
    // TODO
    newArr = arr;
}

int** deepCopy(int** matrix, int r, int c) {
    // create a new matrix with the same dimensions
    if(r <= 0 || c <= 0) return nullptr;
    int** newMatrix = new int*[r];
    for (int i = 0; i < r; i++) {
        newMatrix[i] = new int[c];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    
    // return the new matrix
    return newMatrix;
}
void deleteMatrix(int**& matrix, int r) {
    for (int i = 0; i < r; i++) {
        delete[] matrix[i];
    }
    
    delete[] matrix;
    matrix = NULL;
    cout <<"SUCCESSFUL";
}
void insertRow(int**& matrix, int r, int c, int* rowArr, int row) {
    // create a new matrix with an additional row
    int** newMatrix = new int*[r + 1];
    for (int i = 0; i < r + 1; i++) {
        newMatrix[i] = new int[c];
    }
    
    // copy the elements before the insertion point
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < c; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    
    // copy the inserted row
    for (int j = 0; j < c; j++) {
        newMatrix[row][j] = rowArr[j];
    }
    
    // copy the elements after the insertion point
    for (int i = row; i < r; i++) {
        for (int j = 0; j < c; j++) {
            newMatrix[i + 1][j] = matrix[i][j];
        }
    }
    
    // free the memory for the old matrix
    deleteMatrix(matrix, r);
    
    // update the matrix pointer to point to the new matrix
    matrix = newMatrix;
}
//STRUCT_PRELAB
struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};
void addAddendum(SCP &obj, string addendum) {
    // Student answer
    
    string* addendums = obj.addendums;
    string* newAddendums = new string[obj.numAddendums + 1];
    for(int i = 0; i < obj.numAddendums;i++){
        newAddendums[i] = addendums[i];
    }
    newAddendums[obj.numAddendums] = addendum;
        
        // free the old array memory and assign the new one to obj.addendums
    delete[] addendums;
    obj.addendums = newAddendums;
        
        // increment the numAddendums count
    obj.numAddendums++;
}
//================================================

int main(int argc, const char * argv[]) { // FOR LAB 2
    
//    int p,q;
//    cin>>p>>q;
//    cout<<gcdRecursion(p,q)<< " "<<gcdIteration(p,q);
//    char str[] = "Truong DH Bach Khoa";
//    cout << strLen(str);
//    printPattern(16);
//    cout<<"||";
//    cout << endl;
//    printPattern(-1);
//    int arr[] = {1, 2, 3, 4, 5};
//    int k = 3;
//    cout << getValueAtIndex(arr, k);
//    int a = 5;
//    int b = 6;
//    swap(&a, &b);
//    cout << a << ' ' << b;
//    int *arr = zeros(-1);
//    cout<< *arr;
//    int* arr = new int[2];
//    arr[0] = 2; arr[1] = 3;
//    int* newArr = nullptr;
//    shallowCopy(newArr, arr);
//    cout << newArr[0] << ' ' << newArr[1];
//    delete[] arr;
    
//    int** m = new int*[3];
//    m[0] = new int[2]; m[0][0] = 2; m[0][1] = 2;
//    m[1] = new int[2]; m[1][0] = 1; m[1][1] = 1;
//    m[2] = new int[2]; m[2][0] = 1; m[2][1] = 1;
//    int** n = deepCopy(m, 3, 2);
//    cout << n[0][0] << ' ' << n[0][1] << '\n' << n[1][0] << ' ' << n[1][1]<< '\n' << n[2][0] << ' ' << n[2][1];
//    deleteMatrix(n, 3);
//    string* addendums = new string[1];
//    addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
//
//    SCP obj {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 1};
//
//    addAddendum(obj, "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.");
//
//    cout << obj.addendums[1];
//
//   delete [] obj.addendums;
    return 0;
    
}*/

//==================================LAB3=====================
//====LINKED LIST===============
struct node
{
  int data;
  node *next;
};

node *createLinkedListTail(int n){
    if(n <= 0) return nullptr;
    node *head = nullptr;
    node *tail = nullptr;
    int i = 0;
    while (i < n)
    {
        int value;
        std::cin >> value;

        node *newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {

            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        i++;
    }

    return head;
}
node *createLinkedListHead(int n){
    if(n <= 0) return nullptr;
    node *head = nullptr;
    int i = 0;
    while (i < n)
    {
        int value;
        std::cin >> value;
        node *newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        i++;
    }

    return head;
}
node *insertNode(node *head, node *newNode, int position)
{
    if(position <= 0) return head;
    if(head == nullptr){
        head = newNode;
    }
    else{
        if(position == 1){
            newNode->next = head;
            head = newNode;
        }
        else if(position > 1){
            int idx = 1;
            node *curr = head;
            node *prev = nullptr;
            while(curr != nullptr && idx < position){
                idx++;
                prev = curr;
                curr = curr->next;
            }
            if (curr == nullptr) {  // Reached the end of the linked list
                prev->next = newNode;
            } else {
                newNode->next = curr;
                prev->next = newNode;
            }

        }
    }
    return head;
}
void replace(node* head, int position, int value) {
    if (position < 0 || head == nullptr) {
        return; // Do nothing for invalid position or empty list
    }
    
    int idx = 0;
    node* curr = head;
    
    while (curr != nullptr && idx < position) {
        curr = curr->next;
        idx++;
    }
    
    if (curr != nullptr) {
        curr->data = value;
    }
}

int searchLinkedList(node* head, int key)
{
  // TODO
    node *curr = head;
    int idx = 0;
    while(curr != nullptr){
        if(key == curr->data){
            return idx;
        }
        idx++;
        curr = curr->next;
    }
    return -1;
}

bool isEqual(node *head1, node *head2)
{
    node *current1 = head1;
    node *current2 = head2;


    while (current1 != nullptr && current2 != nullptr)
    {

        if (current1->data != current2->data)
            return false;

        current1 = current1->next;
        current2 = current2->next;
    }


    if (current1 != nullptr || current2 != nullptr)
        return false;

    return true;
}
int countNode(node* head)
{
    node *curr = head;
    int count = 0;
    while(curr != nullptr){
        curr = curr->next;
        count++;
    }
    return count;
    
}

void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}
//============LINKED LIST=============

//============OOP===================
//template <typename T>
//class Array {
//public:
//    Array(int size, T initValue);
//    ~Array();
//
//    void setAt(int idx, const T & value);
//    T getAt(int idx);
//    T& operator[](int idx);
//
//    void print();
//
//private:
//    int size;
//    T * p;
//};
//
//template<typename T>
//void Array<T>::print() {
//    for (int i = 0; i < this->size; ++i) {
//        cout << (i > 0 ? " " : "")
//            << this->p[i];
//    }
//    cout << endl;
//}
//
//// TODO
//template<typename T>
//void Array<T>::setAt(int idx, const T & value){
//
//}
//
//template <typename T>
//T Array<T>::getAt(int idx){
//
//}
//template <typename T>
//T& Array<T>::operator[](int idx){
//    if (idx < 0 || idx >= size) {
//        throw -1; // Throw an exception for invalid index
//    }
//    return p[idx];
//}

//============OOP===================

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    Array(const Array<T> & other); // Copy constructor
    Array<T> & operator=(const Array<T> & other); // Copy assignment operator
    
    void print();

private:
    int size;
    T * p;
};
template<typename T>
Array<T>::Array(int size, T initValue) {
    this->size = size;
    this->p = new T[size];
    for (int i = 0; i < size; ++i) {
        this->p[i] = initValue;
    }
}

template<typename T>
Array<T>::~Array() {
    delete[] p;
}

template<typename T>
Array<T>::Array(const Array<T>& other) {
    cout << "Call copy constructor" << endl;
    this->size = other.size;
    this->p = new T[size];
    for (int i = 0; i < size; ++i) {
        this->p[i] = other.p[i];
    }
}
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    cout << "Call assignment operator" << endl;
    if (this != &other) {
        delete[] p;
        this->size = other.size;
        this->p = new T[size];
        for (int i = 0; i < size; ++i) {
            this->p[i] = other.p[i];
        }
    }
    return *this;
}

template<typename T>
void Array<T>::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << (i > 0 ? " " : "")
            << this->p[i];
    }
    cout << endl;
}

// TODO

// TODO
class Integer{
private:
    int val;
    
public:
    Integer(int);
    Integer(Integer*);
    Integer operator+(const Integer&) const;
    Integer operator+(int) const;
    void print();
};
Integer::Integer(int val){
    this->val = val;
}
Integer::Integer(Integer* others){
    this->val = others->val;
}
void Integer::print() {
    cout << this->val << endl;
}
Integer Integer::operator+(const Integer& other) const {
    return Integer(val + other.val);
}
Integer Integer::operator+(int value) const{
    return Integer(val + value);
}


int main(int argc, const char * argv[]) {   //LAB3
//    int n = 0;
//    cin>> n;
//    node *head = createLinkedListHead(n);
//    int m = 0;
//    cin>> m;
//    node *head2 = createLinkedList(m);
//    cout << isEqual(head1, head2) << endl;
//    print(head);
//    cout<<endl;
//    cout<<countNode(head);
//    cout << endl;
//    int n = 0;
//    cin >> n;
//    node *head = createLinkedListTail(n);
//    int m;
//    cin>>m;
//    cout<<searchLinkedList(head,m);
//    Array<int> * a3;
//    Array<int> * a4 = new Array<int>(10, 3);
//    a3 = new Array<int>(*a4);
//    delete a4;
//    a3->print();
//    delete a3;
    int x, y, z;
    cin >> x >> y >> z;
    Integer a(x);
    Integer b(y);
    Integer* t = new Integer(z);
    Integer c(t);
    
    a.print(); b.print();
    (a + b + c + 4).print();
    
    delete t;
    
    return 0;
}
