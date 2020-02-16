package logica.partida;


import java.util.Iterator;
import java.util.LinkedList;

import logica.valueObjects.VoPartida;

public class Partidas 
{
	private LinkedList <Partida> listaPartidas;
		
	public Partidas()
	{
		listaPartidas = new  LinkedList <Partida>();
	}
	
	public boolean esVacia()
	{
		return listaPartidas.isEmpty();
	}
	
	public int largo()
	{
		return listaPartidas.size();
	}
	
	public void insBack(Partida p)
	{
		listaPartidas.add(p);		
	}
	
	public Partida ultimo()
	{
		return listaPartidas.getLast();		
	}
	
	public VoPartida[] listarPartidas()
	{
		VoPartida[] voPartida = new VoPartida[listaPartidas.size()];
		Iterator<Partida> itr = listaPartidas.iterator();		
		int i = 0;
		while(itr.hasNext())
		{
			Partida partida = itr.next();
			VoPartida p = new VoPartida(partida.getNroPartida(),partida.isFinalizada(),partida.getCantidadIntentos(),partida.getPuntajeFinal(),partida.getNroSecreto());			
			voPartida[i] = p;								
			i++;
		}		
		return voPartida;
		
	}

}
