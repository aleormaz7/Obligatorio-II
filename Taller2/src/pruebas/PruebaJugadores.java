package pruebas;

import logica.jugador.Jugador;
import logica.jugador.Jugadores;
import logica.partida.Partida;
import logica.partida.Partidas;
import logica.valueObjects.VoJugadorGeneral;
import logica.valueObjects.VoPartida;

public class PruebaJugadores
{

	public static void main(String[] args) 
	{
				
		Jugadores jugadores = new Jugadores();
		
		Partidas listaPartidasJ1 = new Partidas();
		
		Jugador j1 = new Jugador("ale","123");
		Jugador j2 = new Jugador("ger","123456");
		
		jugadores.insert(j1);	
		jugadores.insert(j2);
		
		VoJugadorGeneral[] arrayJug = jugadores.listarJugadores();  		

		for(int i = 0; i < arrayJug.length;i++)
		{
			System.out.println("i: "+i);
			System.out.println(arrayJug[i].getNombre());
			System.out.println(arrayJug[i].getCodigoIngreso());
			System.out.println(arrayJug[i].getCantPartidasFinalizadas());
			System.out.println(arrayJug[i].getCociente());
			System.out.println(arrayJug[i].getPuntaje());
		}		
		
		
	
		
		Partida p1 = new Partida(1, 500); 
		Partida p2 = new Partida(2, 250); 
		p1.setFinalizada(true);
		p2.setFinalizada(false);
		
		listaPartidasJ1.insBack(p1);
		listaPartidasJ1.insBack(p2);
		
		VoPartida[] arrayPartidas = listaPartidasJ1.listarPartidas();  
		
		for(int i = 0; i < arrayPartidas.length;i++)
		{
			System.out.println("i: "+i);
			System.out.println(arrayPartidas[i].getNroPartida());
			System.out.println(arrayPartidas[i].getNroSecreto());
			System.out.println(arrayPartidas[i].getCantIntentosRealizados());
			System.out.println(arrayPartidas[i].getPuntajeObtenido());
		}					
		
		j1.registrarPartida();
		
		System.out.println("fin");
	}

}
