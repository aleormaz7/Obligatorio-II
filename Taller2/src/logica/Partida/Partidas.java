package logica.partida;

import java.util.LinkedList;

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
	
	public void ListarPartidas()
	{
		
	}

}
