package grafica;

import excepciones.JugadorExisteException;
import logica.jugador.Jugadores;

public class Fachada 
{
	private Jugadores diccioJugadores;
	
	
	public Fachada()
	{
		diccioJugadores = new Jugadores();
		
	}
	
	public void listarPartidasJuagador(String nom) throws JugadorExisteException
	{
		if(!diccioJugadores.member(nom))
		{
			throw new JugadorExisteException("Jugador ya existe!!");
			
			
		}
		else
		{
			//TODO:
		}
		
		
	}
}
