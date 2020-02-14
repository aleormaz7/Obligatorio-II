package logica.Partida;

import java.util.LinkedList;

public class Partidas 
{
	private LinkedList <Partida> listaPartidas;
	
	
	public Partidas()
	{
		listaPartidas = new  LinkedList <Partida>();
	}
	
	public void insBack(Partida p)
	{
		listaPartidas.add(p);		
	}
	
	

}
