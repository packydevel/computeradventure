import java.util.Iterator;
import java.util.Random;

public class CoffeeGenerator implements Generator<Coffee>, Iterable<Coffee> {
	private Class[] types = { Mocha.class, Cappuccino.class, Americano.class,
			Breve.class };

	private static Random rand = new Random(47);

	public CoffeeGenerator() {
	}

	// For iteration:
	private int size = 0;

	public CoffeeGenerator(int sz) {
		size = sz;
	}

	public Coffee next() {
		try {
			return (Coffee) types[rand.nextInt(types.length)].newInstance();
			// Report programmer errors at run time:
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	// inner class
	class CoffeeIterator implements Iterator<Coffee> {
		int count = size;

		public boolean hasNext() {
			return count > 0;
		}

		public Coffee next() {
			count--;
			// invoca il metodo next della classe esterna
			return CoffeeGenerator.this.next();
		}

		public void remove() { // Not implemented
			throw new UnsupportedOperationException();
		}
	};

	public Iterator<Coffee> iterator() {
		return new CoffeeIterator();
	}

	public static void main(String[] args) {
		CoffeeGenerator gen = new CoffeeGenerator();
		for (int i = 0; i < 5; i++)
			System.out.println(gen.next());

		/*
		 * Crea un oggetto di classe generator invocando il costruttore
		 * opportuno. Crea un iteratore su questo oggetto. Itera sull’iteratore
		 */
		for (Coffee c : new CoffeeGenerator(5))
			System.out.println(c);
	}
	/*
	 * CoffeeGenerator c1 = CoffeeGenerator(5); CoffeIterator i1 =
	 * c1.Iterator(); while(i1.hasNext()){ Coffee c= i1.next();
	 * System.out.println(c); }
	 */
}
