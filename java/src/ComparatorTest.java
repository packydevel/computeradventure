// Implementazione dell’interfaccia Comparator
import java.util.Arrays;
import java.util.Comparator;

class CompTypeComparator implements Comparator {

	public int compare(Object o1, Object o2) {
		int j1 = ((CompType) o1).j;
		int j2 = ((CompType) o2).j;
		return (j1 < j2 ? -1 : (j1 == j2 ? 0 : 1));
	}
}

public class ComparatorTest {
	public static void main(String[] args) {
		CompType[] a = new CompType[10];
		Arrays2.fill(a, CompType.generator());
		Arrays2.print("before sorting, a = ", a);
		Arrays.sort(a, new CompTypeComparator());
		Arrays2.print("after sorting, a = ", a);
	}
}
