import java.util.*; 
class SelectionSort
{
	void sort(int arr[])
	{
		int n = arr.length;

		for (int i = 0; i < n; i++)
		{
			int minima = i;

			for (int j = i + 1; j < n; j++)

				if (arr[j] < arr[minima])

					minima = j;

			int temp = arr[minima];

			arr[minima] = arr[i];

			arr[i] = temp;
		}
	}

	void printArray(int arr[])
	{
		int n = arr.length;

		for (int i=0; i<n; ++i)

			System.out.print(arr[i]+" ");

		System.out.println();
	}

	public static void main(String args[])
	{
		SelectionSort S = new SelectionSort();

		int arr[] = {3, 3, -1, 5, 4, 6, 6, 9};

		Scanner sc = new Scanner(System.in);
		
		// String str = sc.nextLine();

		int a = sc.nextInt();

		int b = sc.nextInt();

		// System.out.print(str);

		// String str2 = sc.nextLine();

		System.out.println(a + b);

		// System.out.print("skjfksdjkf" + "skdfhjskdf");

		S.sort(arr);

		S.printArray(arr);
	}
}
