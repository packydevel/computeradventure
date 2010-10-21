import java.util.ArrayList;
import java.util.List;

class Fruit {
}

class Apple extends Fruit {
}

class Orange extends Fruit {
}

class Jonathan extends Apple {
}

public class CovariantArrays {
	public static void main(String[] args) {
		Fruit[] fruit = new Apple[10];
		
		// Runtime type è Apple[], non Fruit[] o Orange[]
		// Java dunque non può eseguire alcun controllo di tipo a Compile-Time.
		fruit[0] = new Apple(); // OK
		fruit[1] = new Jonathan(); // OK
		
		try {
			// Compiler allows you to add Fruit:
			// errore a run-time, ma non a compile-time
			fruit[0] = new Fruit(); // ArrayStoreException
		} catch (Exception e) {
			System.out.println(e);
		}
		
		try {
			// Compiler allows you to add Oranges:
			// errore a run-time, ma non a compile-time
			fruit[0] = new Orange(); // ArrayStoreException
		} catch (Exception e) {
			System.out.println(e);
		}
		
		// Wildcards allow covariance:
	    List<? extends Fruit> flist = new ArrayList<Apple>();
	    
	    // Le seguenti assegnazioni sono corrette in quanto flist potrebbe fare
	    // riferiento anche ad un ArrayList<Orange>.
	    // A Comile-Time Java non sa che flist è o sarà inizializzato come ArrayList<Apple>.
		// Java dunque esegue il controllo di tipo a Compile-Time.
	    //flist.add(new Apple()); // ERROR!!! Compile-Time
	    // flist.add(new Fruit()); // ERROR!!! Compile-Time
	    // flist.add(new Object()); // ERROR!!! Compile-Time
	    
	    // Rispetto al caso precedente, l'unica assegnazione consentita ma poco interessante è
	    // la segeuente.
	    flist.add(null); // Legal but uninteresting
	    
	    // La seguente assegnazione è corretta perchè Java sa a Compile-Time che potrà
	    // restituire da flist almeno un oggetto di tipo Fruit.
	    Fruit f = flist.get(0);
	}
}