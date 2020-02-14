package logica.Jugador;

import java.util.TreeMap;

public class Jugadores 
{
	private TreeMap <String,Jugador> arbol;
	
	
	public Jugadores()
	{
		arbol = new TreeMap <String,Jugador>() ;
				
	}
	
	
	
	public boolean member(String clave)
	{
		return arbol.containsKey(clave);		
	}
	
	public Jugador find(String clave)
	{
		return (Jugador)arbol.get(clave);
	}
	
	

}
