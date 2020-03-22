#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;

//aþaðýdaki satýrlarý yoruma alarak kodunuzu farklý þekillerde test edebilirsiniz.
#define _TEST_ITERATIVE_
//#define _TEST_RECURSIVE_

// Bu odevde global veya statik degisken tanimlanamaz!!!

/* Ozyinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while kullanamazsiniz ve en az bir kez recursiveFunction
 * fonksiyonu cagri yapilmalidir.
 */
long long recursiveFunction(int numberOfStones)
{
	if (numberOfStones <= 0)
		return 1;

	if (numberOfStones <= 2)
		return numberOfStones;


	return recursiveFunction(numberOfStones - 1) + recursiveFunction(numberOfStones - 2) + recursiveFunction(numberOfStones - 3);

}

/* Yinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while dongusu kullanilmalidir.
 * Bu fonksiyon icinde baska bir fonksiyona (kendisi dahil) cagri yapilamaz.
 */
long long iterativeFunction(int numberOfStones)
{
	if (numberOfStones <= 0)
		return 0;

	if (numberOfStones <= 2)
		return numberOfStones;

	long long * arr = new long long[numberOfStones + 1];

	// ilerki sayýlarý 1, 2 ve 3 ün toplamý olarak yazmamýz gerekiyor ondan dolayý base memberleri ilklendiriyoruz
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= numberOfStones; i++)
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];

	// arr[3] => 2 + 1 + 1 = 4
	// arr[4] => 4 + 2 + 1 = 7
	// arr[5] => 7 + 4 + 2 = 13
	// ..
	// arr[number] => ways of writing number as 1, 2 and 3 sums

	return arr[numberOfStones];
}



int main()
{
	const int MAX_NUMBER_OF_STONES{ 72 };

	cout << setfill(' ');

	cout.imbue(locale(""));

	for (auto i = 1; i <= MAX_NUMBER_OF_STONES; ++i)
	{

#ifdef _TEST_ITERATIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = iterativeFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();


			cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
		}
#endif

#ifdef _TEST_RECURSIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = recursiveFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "recursive" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n\n";
		}
#endif

	}

	return 0;
}