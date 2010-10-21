import java.util.AbstractList;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class Holder<T> {
	private T value;

	public Holder() {
	}

	public Holder(T val) {
		value = val;
	}

	public void set(T val) {
		value = val;
	}

	public T get() {
		return value;
	}

	public boolean equals(Object obj) {
		return value.equals(obj);
	}

	public static void main(String[] args) {
		Holder<Apple> apple = new Holder<Apple>(new Apple());

		Apple d = apple.get();

		apple.set(d);

		// Holder<Fruit> fruit = apple; // Cannot upcast

		Holder<? extends Fruit> fruit = apple; // OK

		Fruit p = fruit.get();

		d = (Apple) fruit.get();

		try {
			Orange c = (Orange) fruit.get(); // No warning
		} catch (Exception e) {
			System.out.println(e);
		}

		// fruit.set(new Apple()); // Cannot call set()
		// fruit.set(new Fruit()); // Cannot call set()
		System.out.println(fruit.equals(d)); // OK

		List<? super Apple> apples = new ArrayList<Fruit>();

		apples.add(new Apple());
		apples.add(new Jonathan());
		// apples.add(new Fruit()); // Error Why???

		Holder<Number> h = new Holder<Number>();

		h.set(new Integer(0)); // OK
		h.set(new Double(0)); // OK

		// h.set(new String("0")); // ERROR!!! Compile-Time

		// Data la seguente dichiarazione delle variabili abl e arl ...
		AbstractList<Number> abl;
		ArrayList<Integer> arl = new ArrayList<Integer>();

		// La seguente assegnazione non è corretta in quanto un
		// ArrayList<Integer> non
		// è sottoclasse di AbstractList<Number> sebbene ArrayList sia
		// sottoclasse di
		// AbstractList.
		// Java dunque esegue il controllo di tipo a Compile-Time.
		// abl = arl; // // ERROR!!! Compile-Time

		// Data la seguente dichiarazione delle variabili abl2 e arl2 ...
		AbstractList<Number> abl2;
		ArrayList<Number> arl2 = new ArrayList<Number>();

		// La seguente assegnazione è corretta in quanto un ArrayList<Number>
		// è sottoclasse di AbstractList<Number> in quanto ArrayList è
		// sottoclasse di
		// AbstractList e il parametro di tipo è lo stesso.
		// Java dunque esegue il controllo di tipo a Compile-Time.
		abl2 = arl2; // OK

		// Data la seguente dichiarazione delle variabili abl3 e arl3 ...
		AbstractList<Number> abl3;
		AbstractList<Integer> arl3 = new ArrayList<Integer>();

		// La seguente assegnazione non è corretta in quanto un
		// AbstractList<Number> non
		// è uguale a un AbstractList<Integer> sebbene le variabili siano
		// entrambe di tipo
		// AbstractList.
		// Java dunque esegue il controllo di tipo a Compile-Time.
		// abl3 = arl3; // // ERROR!!! Compile-Time

		// Data la seguente dichiarazione delle variabili abl4 e arl4 ...
		AbstractList<? extends Number> abl4;
		AbstractList<Integer> arl4 = new ArrayList<Integer>();

		// La seguente assegnazione è corretta in quanto un
		// AbstractList<Integer>
		// può essere assegnato a un AbstractList<? extends Number> dato che il
		// parametro
		// di tipo di ques'ultimo ammette qualunque sottoclasse di Number.
		// Java dunque esegue il controllo di tipo a Compile-Time.
		abl4 = arl4; // OK

		// Data la seguente dichiarazione delle variabili abl4 e arl4 ...
		AbstractList<? extends Number> abl5;
		ArrayList<Integer> arl5 = new ArrayList<Integer>();

		// La seguente assegnazione è corretta in quanto un ArrayList<Integer>
		// può essere assegnato a un AbstractList<? extends Number> dato che
		// ArrayList è
		// sottoclasse di AbstractList e in più il parametro di tipo di
		// ques'ultimo
		// ammette qualunque sottoclasse di Number.
		// Java dunque esegue il controllo di tipo a Compile-Time.
		abl5 = arl5; // OK

		ArrayList<? extends Number> aln;

		ArrayList<Integer> ali = new ArrayList<Integer>();
		ali.add(0);
		ali.add(1);
		ali.add(2);

		// Sulla base delle precedenti dichiarazioni è corretto assegnare ali ad
		// aln
		aln = ali; // OK

		// Non è corretto eseguire il metodo add su aln in quanto aln è definito
		// con
		// parametro di tipo ? che seppure bounded non consente a Java di
		// controllare
		// a compile-time di verificare il tipo di oggetto assegnato.
		// Java dunque esegue il controllo di tipo a Compile-Time.
		// aln.add(3); // ERROR!!! Compile-Time

		// Al contrario è possibile recuperare gli elementi col metodo get
		// perchè
		// Java sa che per come è definito aln sicuramente potrà restituire
		// oggetti di
		// tipo Number.
		aln.get(2); // OK.

		// Delle seguenti dichiarazioni corrette, ciò che occorre osservare è
		// che invocando
		// il metodo fromArrayToCollection Java esegue l'inferenza di tipo
		// individuando il tipo sconosciuto T come quello meno specifico tale da
		// consentire l'esecuzione del metodo.
		// Java dunque esegue il controllo di tipo a Compile-Time.
		Object[] oa = new Object[100];
		Collection<Object> co = new ArrayList<Object>();
		fromArrayToCollection(oa, co); // T inferred to be Object

		String[] sa = new String[100];
		Collection<String> cs = new ArrayList<String>();
		fromArrayToCollection(sa, cs); // T inferred to be String
		fromArrayToCollection(sa, co); // T inferred to be Object

		Integer[] ia = new Integer[100];
		Float[] fa = new Float[100];
		Number[] na = new Number[100];
		Collection<Number> cn = new ArrayList<Number>();
		fromArrayToCollection(ia, cn); // T inferred to be Number
		fromArrayToCollection(fa, cn); // T inferred to be Number
		fromArrayToCollection(na, cn); // T inferred to be Number
		fromArrayToCollection(na, co); // T inferred to be Object

		// In questo caso, l'invocazione del metodo fromArrayToCollection
		// fornisce
		// un errore di compilazione in quanto Java non riesce ad inferire il
		// tipo corretto tra Number e String in quando le due classe non sono
		// legate
		// da un percorso comune nell'albero dell'ereditarietà delle Java
		// Collections
		// Java dunque esegue il controllo di tipo a Compile-Time.
		// fromArrayToCollection(na, cs); // ERROR!!! Compile-Time

	}

	static <T> void fromArrayToCollection(T[] a, Collection<T> c) {
		for (T o : a) {
			c.add(o); // Correct
		}
	}

}