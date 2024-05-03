/*
Implement three following hashing function:

long int midSquare(long int seed);
long int moduloDivision(long int seed, long int mod);
long int digitExtraction(long int seed, int* extractDigits, int size);

Note that:

In midSquare function: we eliminate 2 last digits and get the 4 next digits.

In digitExtraction: extractDigits is a sorted array from smallest to largest index of digit in seed (index starts from 0). The array has size size.
*/

long int midSquare(long int seed)
{
    seed = pow(seed,2);
    seed/=100;
    return seed %10000;
    
 
}

long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
    

}

long int digitExtraction(long int seed,int* extractDigits,int size)
{
   string str_seed = to_string(seed);
   string str_result = "";
   for(int i = 0 ; i < size; i++)
   {
       str_result += str_seed.substr(extractDigits[i],1);
       
   }
   return stoll(str_result);

}

void implement() {
    int a[]={1,2,5};
    cout << digitExtraction(122443,a,3);
}

