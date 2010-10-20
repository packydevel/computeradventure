// Utilities to simplify generic container creation
// by using type argument inference.

import java.util.*;

public class New {
	public static <K, V> Map<K, V> map() {
		return new HashMap<K, V>();
	}

	public static <T> List<T> list() {
		return new ArrayList<T>();
	}

	public static <T> LinkedList<T> lList() {
		return new LinkedList<T>();
	}

	public static <T> Set<T> set() {
		return new HashSet<T>();
	}

	public static <T> Queue<T> queue() {
		return new LinkedList<T>();
	}
	
	public static void f1(List<String> l) {
	}
	
	public static void f2(List<Object> l) {
	}

	// Examples:

	public static void main(String[] args) {
		// Il metodo map() non conosce i tipi passati
		// per argomento
		Map<String, List<String>> sls = New.map();
		
		sls.put("first", new ArrayList<String>()); // OK - Java inferisce i tipi K e V
		System.out.println(sls.containsKey("first")); // OK
		
		// Non compila.
		// Java non inferisce il tipo T quando il risultato di un metodo
		// generico viene passato ad un altro metodo (f1).
		// Java in questo caso associa al tipo T la classe Object di default.
		//f1(New.list()); // ERROR!!! At Compile-Time
		
		// Per risolvere il problema occorre specificare in fase di invocazione
		// di f1 il parametro di tipo con cui si invoca il metodo generico.
		f1(New.<String>list()); // OK
		
		// Una alternativa sarebbe quella di dichiarare Object il tipo parametrizzato
		// da f1 come nel caso di f2.
		f2(New.list()); // OK
		
		List<String> ls = New.list();
		LinkedList<String> lls = New.lList();
		Set<String> ss = New.set();
		Queue<String> qs = New.queue();
	}
}