package pruebas;

import logica.jugador.Jugador;
import logica.jugador.Jugadores;

public class PruebaJugadores
{

	public static void main(String[] args) 
	{
		
		
		Jugadores jugadores = new Jugadores();
		
		Jugador j1 = new Jugador("ale","123");
		Jugador j2 = new Jugador("ger","123");
		
		jugadores.insert(j1);
		jugadores.insert(j2);
		
		
		jugadores.listarJugadores();
		
		
		

	}

}
