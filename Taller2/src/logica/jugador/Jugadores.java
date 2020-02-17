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
	
	public boolean member(String nom)
	{		
		return arbol.containsKey(nom);		
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
		Collection<Jugador> c = arbol.values();
		Iterator<Jugador> itr = c.iterator();
		int i = 0;
		while(itr.hasNext())
		{
			Jugador jug = itr.next();	
			VoJugadorGeneral j = new VoJugadorGeneral(jug.getNombre(),jug.getPuntajeTotal(),jug.getCantidadPartidasFinalizadas(),jug.getCociente(),jug.getCodigoIngreso());			
			voJugGeneral[i] = j;
			//System.out.println("Nom: "+j.getNombre());
			i++;
		}
		
		return voJugGeneral;
	}
	
	//.................??
	public int largo()
	{
		return arbol.size();
	}
	
}
