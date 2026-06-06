#include <iostream>

using namespace std;

int main() {

int data[50];

int count = 0;
int sum = 0;

int len = 0;
int i = 0;
cin >> len;

while (i <len){
cin >> data[i];
i++;
}

i=0;

while (i <len) {
if (data[i] % 13 ==0 || data[i] % 20 == 0)
{
    sum += data[i];
    count++;
}
i++;
}

cout << count << endl << sum;

return 0;
}




#include <iostream>

using namespace std;

int main(){
int data [100];
int len;
cin >> len;
int i=0;
int sum=0;
while (i<len) {
cin >> data [i] ;
i++;
}
i=0;
while (i<len){
if (data [i]% 10 == 8)
sum= sum+ data[i];
i++;
}
cout << sum;


}



