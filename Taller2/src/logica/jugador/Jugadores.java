package logica.jugador;

import java.util.Collection;
import java.util.Iterator;
import java.util.TreeMap;

import logica.valueObjects.VoJugadorGeneral;
import logica.valueObjects.VoRanking;


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
		
		//opcion no valida....??
		/*int i = 0;
		for (Jugador obj : arbol.values())
		{
			VoJugadorGeneral j = new VoJugadorGeneral(obj.getNombre(),obj.getPuntajeTotal(),obj.getCantidadPartidasFinalizadas(),obj.getCociente(),obj.getCodigoIngreso());			
			voJugGeneral[i] = j;
			i++;
		}*/
		
		return voJugGeneral;
	}
	
	
	//.................??
	public VoRanking[] listarJugadoresRanking()
	{
		VoRanking[] voRank = new VoRanking[arbol.size()];
		
		Collection<Jugador> c = arbol.values();
		Iterator<Jugador> itr = c.iterator();
		int i = 0;
		while(itr.hasNext())
		{
			Jugador jug = itr.next();	
			VoRanking j = new VoRanking(jug.getNombre(),jug.getPuntajeTotal(),jug.getCantidadPartidasFinalizadas(),jug.getCociente(),0);
			voRank[i] = j;		
			i++;
		}
		
		
		//opcion no valida....??
		/*int i = 0;		
		for (Jugador obj : arbol.values())
		{		
			VoRanking j = new VoRanking(obj.getNombre(),obj.getPuntajeTotal(),obj.getCantidadPartidasFinalizadas(),obj.getCociente(),0);
			voRank[i] = j;
			i++;								
		}*/		
		
		//TODO:ORDENAR POR COCIENTE
		for(i=0; i < voRank.length-1 ; i++)
		{			
            for(int j = i+1; j < voRank.length; j++)
			{           	
				if(voRank[j].getCociente() > voRank[i].getCociente())
				{			
					VoRanking aux = voRank[i];	
                    voRank[i]=voRank[j];
                    voRank[j]=aux;                 
				}		
			} 		
		}
		
		for(i=0; i < voRank.length; i++)	
			voRank[i].setPosicion((i+1));
			
        return voRank;				
	}
	
}
