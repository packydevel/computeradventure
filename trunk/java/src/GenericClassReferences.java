public class GenericClassReferences {
	public static void main (String[] args) {
		Class intClass = int.class;
		Class<Integer> integerClass = int.class;
		
		integerClass = Integer.class;
		
		// Questa assegnazione può essere fatta in quanto intClass è di tipo Class
		// senza specificare il parametro di tipo.
		// Java dunque non può eseguire alcun controllo di tipo a Compile-Time.
		intClass = double.class; // OK
		
		// Questa assegnazione non può essere fatta in quanto integerClass è di tipo Class
		// con parametro di tipo: Integer.
		// Java dunque esegue il controllo di tipo a Compile-Time.
		//integerClass = double.class; // ERROR!!! Compile-Time
	
		Class<?> anyClass = int.class;
	
		// Le seguenti assegnazioni sono corrette in quanto anyClass è di tipo Class
		// con parametro di tipo: ?
		// Java dunque consente l'assegnazione ad anyClass di qualunque tipo diClass.
		// Java dunque esegue il controllo di tipo a Compile-Time.
		anyClass = float.class; // OK
		anyClass = double.class; // OK
		
		Class<? extends Number> boundedClass = int.class;
		
		boundedClass = float.class; // OK
		boundedClass = double.class; // OK
		
		// Questa assegnazione non può essere fatta in quanto boundedClass è di tipo Class
		// con parametro di tipo: ? extends Number.
		// Ciò significa che accetta qualunque parametro di tipo che estenda derivi da Number.
		// String evidentemente non deriva da Number;
		// Java dunque esegue il controllo di tipo a Compile-Time.
		// boundedClass = String.class; // ERROR!!! Compile-Time
	}
}