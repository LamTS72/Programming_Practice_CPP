#include <iostream>
//#include<cstring>
#include<fstream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

//============================LAB_1==================================
void process(char str[], char outstr[]){
    size_t length = strlen(str);
    int i = 0;
    int j = -1;
    remove heading space
    while (++j < length && str[j] == ' ');
    for(;j<length;j++){
        if(str[j] == ' '){
            if(str[j-1]== ' '){
                continue;
            }
        }
        outstr[i++] = str[j];
    }
    remove tailing space
    while(i-- >0 && outstr[i] == ' ' );
    outstr[i+1] = '\0';

}
void process(const char *str, char *outstr) {
     TODO
    size_t n = strlen(str);
    outstr[n + 1];
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
     TODO
    ifstream myFile;   declare a file

    myFile.open(fileName);  open the file
    int sum = 0;
    int num;
    while ((myFile >> num) )  reading a line from the file while possible
    {
        
        sum = sum + num;     convert string to number and add it to the sum
    }

    myFile.close();    closing the file
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

55 85 47 58        { 88,72,65,37},;
31 04 60 67         {82,84,34,12}
94 69 71 73         {74,46,88,44}}
51 62 64 90
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
            cout<<temp1<<" ";
        }
        i++;
    }
    cout<<endl;
    while(j >= 0){
        if(t >= 0){
            temp2 += arr[j][t];
            t--;
            cout<<temp2<<" ";
        }
        j--;
    }
    result1 = temp1 + temp2 - arr[x][y] ;
    cout<<result1<<" ";
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
    cout<<result2<<" ";
    result = result1 - result2;
    if(result < 0){
        return -result;
    }
    return result;
}


void uppercase(string output)   {
     TODO
    string temp;
    getline(cin,temp);

    fstream myFile;

    //long n = temp.length();
    //cout<<n;
 //   string temp;

    for(int i = 0;i<temp.length();i++){
        if(temp[i] >= 'a' && temp[i] <= 'z'){
            temp[i] = temp[i] - 32;
        }
    }
    string words = temp;
    myFile.open(output);
    if(myFile.is_open()){
        cout<<"error";
    }
    myFile << words;
    //cout << ;
    myFile.close();
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
     TODO
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
     TODO
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
     TODO
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
     TODO
    int res = 0;
    for(int i = 0; i < numEls ; i++){
        res += array[i];
    }
    result = res;
}

bool completeNum(int N)
{
     TODO
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
     TO DO
    if(index >= s.length() || index < 0){
        return;
    }
    cout<<s.substr(index,s.length());
    cout<<s.length();
}

void findAllIndex(string s1, string s2){
     TO DO
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
     TODO
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
                i++;
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
            cout<<j<<endl;
        }

    }
    while(i-- >0 && outstr[i] == ' ' );
    outstr[i+1] = '\0';
    
}

void printFirstRepeatedWord(char str[]) {
     TODO
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
    bool found = false;
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
     Write your code here
    size_t length = strlen(str);
    int length = 0;
    int i = 0;
    while(str[i] != 0){
        ++length;
        i++;
    }
    cout << length;
    for(int i = 0; i < length;i++){
        if(str[i] != str[length-i-1]){
            return false;
        }
    }
    return true;
}
bool isSpecialNumber(int n) {
     Write your code
     
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
     Write your code
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
    int base = 1;
    long int sum = 0;
    //int temp = ;
    while(decimal_number != 0){
        sum += (decimal_number%2)*base;
        base = base * 10;
        decimal_number = decimal_number/2;
    }
    return sum;
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
     Write your code
    encrypt(text,-shift) ;
    
}
void replaceString(string s, string s1, string s2){
    TO DO
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
    TO DO
    int i = 0;
    int index = -1;
    while(i < s.length()){
        if (s.substr(i,s1.length()).find(s1) != -1) {

        }
        i++;
    }
    string str;
    while(s.size()!=0&&s.find(s1)<s.size()){
        str = s.erase(s.find(s1),s1.size());
    }
    cout << str;
    size_t n = s.length();
    size_t k = s1.length();

     string t(n, ' ');
     int j = 0;  // t's index

     for (int i = 0; i < n; ++i) {
       t[j++] = s[i];
       if (j >= k && t.substr(j - k, k) == s1)
         j -= k;
     }
    cout << t.substr(0, j);
    string str;
        auto f = s.find(s1);find method return the heading position which is the same original string.
            while (f != string::npos) {
                s.erase(f, s1.size());
                f = s.find(s1);
            }
    str = s;
    cout << str;
    
}
//============================LAB_1================================== */
int main(int argc, const char * argv[]) { //FOR LAB 1
        string name = "/Users/chessman/Desktop/Xcode/example_cpp/example_cpp/test.txt";
        calSum(name);
        int arr[][1000] = {{-44,64,-6},{87,92,-19},{-92,53,-38},{-39,-92,21}};
        cout << findMaxColumn(arr, 4, 3);
        int arr[][1000] = {{-92,78,-2,-58,-37},{44,-4,30,-69,22}};
        cout << findMaxColumn(arr, 2,5);
        int arr[][1000] = {{-45,18,-37},{-2,-31,24},{-48,-33,-48}};
        cout << diagonalProduct(arr,3,3);
        string words;
        cin >> words;
        int max = 0;
        int length = 0;
        int i = 0;
        //cout<<words.length();
        while(i < words.length()){
            if(words[i] != words[i-1]){
                length = 0;
            }
            ++length;
            if(length > max){
                max = length;
            }
            i++;
        }
        cout<<max;
        int arr[][1000] = {{1,9,6}, {4,5,3}, {6,3,9}};
        cout << isSymmetric(arr,3,3);
    chi
        int arr[][1000] = {{55,85,47,58},{31,4,60,67},{94,69,71,73},{51,62,64,90}};
        cout << diagonalDiff(arr,4,4,1,2);
        int arr[][1000] = {{88,72,65,37},{82,84,34,12},{74,46,88,44}};
        cout << diagonalDiff(arr,3,4,1,0);
        return 0;
        int N; cin >> N;
        cout<<completeNum(N);
    88,72,65,37
    82,84,34,12
    74,46,88,44
    
        string s = "Truong Dai Hoc Bach Khoa.";
        cutString(s, 1);
    
        string s1 = "Truong Dai Hoc Bach Khoa.";
        string s2 = "a";
        findAllIndex(s1, s2);
    
    const int MAX_SIZE = 100;
    char str[] = "  !  doAn      VAN   *((   )hau @!#$     " ;
    char outstr[100];
    process1(str, outstr);
    cout << outstr;
    cout<<"|";
    char str[] = "car taxi bike bike car taxi" ;
    printFirstRepeatedWord(str);
    int arr[][1000] = {{32,4,9},{-80,37,71},{-91,-79,-55}};
    cout << ascendingRows(arr,3, 3);
    int arr[][1000] = {{-28,-8,-60,18},{-100,44,-1,24},{-94,92,-70,75}};
    cout << ascendingRows(arr,3,4);
    int arr[][1000] = {{-64,-28,-3,64},{-56,90,57,-31}};
    cout << primeColumns(arr,2,4);
    int arr[][1000] = {{34,-15,11,-70,-23,24},{-39,-90,63,-45,-52,48},{-42,92,55,92,82,81}};
    cout << primeColumns(arr,3,6);
    const char* str = "abba";
    cout << isPalindrome(str);
    const char* str = "axz";
    cout << isPalindrome(str);
    int n;
    cin >> n;
    cout << isSpecialNumber(n);
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << checkElementsUniqueness(arr, n);
    delete[] arr;
    cout << decimalToBinary(20);
    cout << decimalToBinary(192);
    
    int n, shift;
    cin >> n >> shift;
    char* text = new char[n+1];
    for(int i = 0; i < n; i++) cin >> text[i];
    text[n] = 0;

    encrypt(text, shift);
    cout << text << '\n';
    decrypt(text, shift);
    cout << text;

    delete[] text;
    string name = "/Users/chessman/Desktop/Xcode/example_cpp/example_cpp/test.txt";
    threeChars(name);
    process3(name);
    string s = "Truong Dai Hoc Bach Khoa, Sai Gon";
    string s1 = "ai";
    string s2 = "ong";
    replaceString(s, s1, s2);
    string s = "Truong Dai Hoc Bach Khoa, Sai Gon";
    string s1 = "ai ";
    deleteWord(s, s1);
    
}
