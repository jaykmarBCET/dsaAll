public class Sorting {

  public static void quickSort(int[] arr, int low, int high) {
      if (low < high) {
          int pivotIndex = partition(arr, low, high); 

          quickSort(arr, low, pivotIndex - 1);
          quickSort(arr, pivotIndex + 1, high);
      }
  }

  public static int partition(int[] arr, int low, int high) {
      int pivot = arr[high];
      int i = low - 1;
      for (int j = low; j < high; j++) {
          if (arr[j] < pivot) {
              i++;
              int temp = arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
          }
      }
      int temp = arr[i + 1];
      arr[i + 1] = arr[high];
      arr[high] = temp;
      return i + 1;
  }

  public static void mergeSort(int arr[],int left,iint right){
    if(left==right){
        return;
    }
    int mid = left + (right-left)/2;

    mergeSort(arr, left, mid-1);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
  public static void merge(int arr[],int  left,int mid,int right){

    int i = left;
    int j = mid+1;
    int k =0;
    int temp[] = new int[right-left+1];

  }

  public static void main(String[] args) {
      int[] arr = {65, 4, 6, 7, 3, 5, 78, 8, 4, 7, 4, 7};
      quickSort(arr, 0, arr.length - 1); 
      for (int i : arr) {
          System.out.print(i + " ");
      }
  }
}
