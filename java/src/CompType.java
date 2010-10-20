import java.util.Arrays;
import java.util.Random;

import sun.nio.cs.Surrogate.Generator;

public class CompType implements Comparable {
	int i;
	int j;
	private static Random r = new Random();

	public CompType(int n1, int n2) {
		i = n1;
		j = n2;
	}

	public String toString() {
		return "[i = " + i + ", j = " + j + "]";
	}

	public int compareTo(Object rv) {
		int rvi = ((CompType) rv).i;
		return (i < rvi ? -1 : (i == rvi ? 0 : 1));
	}

	private static int randInt() {
		return Math.abs(r.nextInt()) % 100;
	}

	public static Generator generator() {
		return new Generator() {
			public Object next() {
				return new CompType(randInt(), randInt());
			}
		};
	}

	public static void main(String[] args) {
		CompType[] a = new CompType[10];
		Arrays2.fill(a, generator());
		Arrays2.print("before sorting, a = ", a);
		Arrays.sort(a);
		Arrays2.print("after sorting, a = ", a);
	}
}
