package logica.jugador;

import java.util.Collection;
import java.util.Iterator;
import java.util.TreeMap;

import logica.valueObjects.VoJugadorGeneral;


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
	
	public void insert(Jugador j) 
	{		
		arbol.put(j.getNombre(), j);	
	}
	
	public Jugador find(String clave)
	{
		return (Jugador)arbol.get(clave);
	}
	
	public VoJugadorGeneral[] listarJugadores()
	{
		VoJugadorGeneral[] voJugGeneral = new VoJugadorGeneral[arbol.size()];
		Collection c = arbol.values();
		Iterator itr = c.iterator();
		while(itr.hasNext())
		{
			int i = 0;
			Jugador jug =(Jugador)itr.next();
			VoJugadorGeneral j = new VoJugadorGeneral(jug.getNombre(),jug.getPuntajeTotal(),jug.getCantidadPartidasFinalizadas(),jug.getCociente(),jug.getCodigoIngreso());
			voJugGeneral[i] = j;
			i++;
		}
		
		return voJugGeneral;

	}
	
}
