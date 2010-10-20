import java.util.*;

public class ErasedTypeEquivalence {
	public static void main(String[] args) {
		Class c1 = new ArrayList<String>().getClass();
		Class c2 = new ArrayList<Integer>().getClass();
		System.out.println(c1==c2);
		
		// Le seguenti informazioni dicono solo qual'è il nome del parametro di
		// tipo usato nel codice sorgente Java che implementa ArrayList
		System.out.println(Arrays.toString(c1.getTypeParameters()));
		System.out.println(Arrays.toString(c1.getTypeParameters()));
		
		// Come recuperare a runtime i tipi String e Integer che sono stati
		// utilizzati nell'esempio per parametrizzare gli ArrayList c1 e c2 ???
	}
}