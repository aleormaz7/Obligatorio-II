package pruebas;


import excepciones.JugadorCodigoIncorrectoException;
import excepciones.JugadorExisteException;
import excepciones.NoHayPartidaDisponibleException;
import excepciones.PartidaEnCursoException;
import excepciones.PartidaFinalizadaException;
import grafica.Fachada;
import logica.enumerados.EResultado;
import logica.jugador.Jugador;
import logica.valueObjects.VoJugadorGeneral;
import logica.valueObjects.VoPartida;
import logica.valueObjects.VoPartidaEnCurso;
import logica.valueObjects.VoRanking;

public class PruebaFachada 
{
	public static void main(String[] args)
	{
		Fachada f = new Fachada();
				
		//Registrar Jugador:
		//Jugador 1
		String nom = "juan";
		String cod = "123";
		//Jugador 2
		String nom2 = "pepe";
		String cod2 = "456";
		//Jugador 3
		String nom3 = "ale";
		String cod3 = "789";
		
		try 
		{			
			f.registrarNuevoJugador(nom, cod);			
		}
		catch (JugadorExisteException e)
		{
			System.out.println(e.darMensaje());			
		}
		
		try 
		{			
			f.registrarNuevoJugador(nom2, cod2);			
		}
		catch (JugadorExisteException e)
		{
			System.out.println(e.darMensaje());			
		}
		
		try 
		{			
			f.registrarNuevoJugador(nom3, cod3);			
		}
		catch (JugadorExisteException e)
		{
			System.out.println(e.darMensaje());			
		}
		
		
		
		
		//ListarJugadores:
		VoJugadorGeneral[] arrayJugAux = new VoJugadorGeneral[f.jugadores.listarJugadores().length];		
		arrayJugAux = f.jugadores.listarJugadores();  		
		for(int i = 0;i < arrayJugAux.length; i++)
		{		
			System.out.print("Jugador: "+(i+1));
			System.out.print(" - Nombre: "+arrayJugAux[i].getNombre());
			System.out.print(" - Codigo: "+arrayJugAux[i].getCodigoIngreso());
			System.out.print(" - Puntaje: "+arrayJugAux[i].getPuntaje());
			System.out.print(" - Cant Partidas Finalizadas: "+arrayJugAux[i].getCantPartidasFinalizadas());
			System.out.print(" - Cociente: "+arrayJugAux[i].getCociente());
			System.out.println("");			
		}
		

		//RegistrarPartida/iniciarNuevaPartida: - Jugador1	
		//Jugador1Partida1
		try
		{
			f.iniciarNuevaPartida(nom, cod);
		}
		catch(JugadorExisteException e1 )
		{
			System.out.println(e1.darMensaje());
		}
		catch(JugadorCodigoIncorrectoException e2)
		{
			System.out.println(e2.darMensaje());
		}
		catch(PartidaEnCursoException e3)
		{
			System.out.println(e3.darMensaje());
		}
		
		//Jugador1Partida2
		/*try
		{
			f.iniciarNuevaPartida(nom, cod);
		}
		catch(JugadorExisteException e1 )
		{
			System.out.println(e1.darMensaje());
		}
		catch(JugadorCodigoIncorrectoException e2)
		{
			System.out.println(e2.darMensaje());
		}
		catch(PartidaEnCursoException e3)
		{
			System.out.println(e3.darMensaje());
		}*/
		
		
		//ListarPartidas: - Jugador1	
		try
		{
			VoPartida[] arrayPartidasJ1 =  new VoPartida[f.listarPartidasJuagador(nom).length];
			arrayPartidasJ1 = f.listarPartidasJuagador(nom);
			for(int i = 0; i < arrayPartidasJ1.length;i++)
			{
				System.out.println("Partida: "+(i+1));
				System.out.println("NroPartida: "+arrayPartidasJ1[i].getNroPartida());
				System.out.println("Finalizada: "+arrayPartidasJ1[i].isFinalizada());	
				System.out.println("Intentos Realizados: "+arrayPartidasJ1[i].getCantIntentosRealizados());
				System.out.println("Puntaje: "+arrayPartidasJ1[i].getPuntajeObtenido());
				System.out.println("NroSecreto: "+arrayPartidasJ1[i].getNroSecreto());
			}			
		}
		catch(JugadorExisteException e)
		{
			System.out.println(e.darMensaje());
		}
		
		
		//Login:
		try
		{
			f.login(nom, cod);
		}
		catch(JugadorExisteException e1)
		{
			e1.darMensaje();
		}
		catch(JugadorCodigoIncorrectoException e2)
		{
			e2.darMensaje();
		}
		
		
		
		//Visualizar Partida en Curso:
		try
		{
			VoPartidaEnCurso voPartidaEnCurso = f.visualizarPartidaEnCurso(nom, cod);
			System.out.println("PartidaEnCurso: ");
			System.out.println("NroPartida: "+ voPartidaEnCurso.getNroPartida());
			System.out.println("Finalizada: "+ voPartidaEnCurso.isFinalizada());
			System.out.println("Intetnos Realizados: "+ voPartidaEnCurso.getCantIntentosRealizados());
			System.out.println("Puntaje Obtenido: "+ voPartidaEnCurso.getPuntajeObtenido());
		}
		catch(JugadorExisteException e1)
		{
			e1.darMensaje();
		}
		catch(JugadorCodigoIncorrectoException e2)
		{
			e2.darMensaje();
		}
		catch(NoHayPartidaDisponibleException e3)
		{
			e3.darMensaje();
		}
				
		
		
		//realizarIntento:	
		try
		{
			EResultado resu = f.realizarIntento(nom, cod, 100);//
			if(resu == EResultado.ACIERTO)
			{
				System.out.println("ACIERTO");
			}
			else if(resu == EResultado.MAYOR)
			{
				System.out.println("MAYOR");
			}
			else if(resu == EResultado.MENOR)
			{
				System.out.println("MENOR");
			}
		}
		catch(JugadorExisteException e1)
		{
			e1.darMensaje();
		}
		catch(JugadorCodigoIncorrectoException e2)
		{
			e2.darMensaje();
		}
		catch(NoHayPartidaDisponibleException e3)
		{
			e3.darMensaje();
		}
		catch(PartidaFinalizadaException e4)
		{
			e4.darMensaje();
		}

		
		//abandonarPartida:		
		try
		{
			f.aboandonarPartida(nom, cod);
		}
		catch(JugadorExisteException e1)
		{
			e1.darMensaje();
		}
		catch(JugadorCodigoIncorrectoException e2)
		{
			e2.darMensaje();
		}
		catch(NoHayPartidaDisponibleException e3)
		{
			e3.darMensaje();
		}
		catch(PartidaFinalizadaException e4)
		{
			e4.darMensaje();
		}
		
		
		//
		Jugador j1 = f.jugadores.find(nom);
		j1.setCociente(500);

		Jugador j2 = f.jugadores.find(nom2);
		j2.setCociente(100);

		Jugador j3 = f.jugadores.find(nom3);
		j3.setCociente(250);
		//
		
		//rankingGlobal:
		VoRanking[] arrayJugRankAux = new VoRanking[f.jugadores.listarJugadoresRanking().length];		
		arrayJugRankAux = f.jugadores.listarJugadoresRanking();  		
		for(int i = 0;i < arrayJugRankAux.length; i++)
		{		
			System.out.print("Ranking: "+(i+1));
			System.out.print(" - Nombre: "+arrayJugRankAux[i].getNombre());
			System.out.print(" - Puntaje: "+arrayJugRankAux[i].getPuntaje());
			System.out.print(" - Cant Partidas Finalizadas: "+arrayJugRankAux[i].getCantPartidasFinalizadas());
			System.out.print(" - Cociente: "+arrayJugRankAux[i].getCociente());
			System.out.print(" - Posicion: "+arrayJugRankAux[i].getPosicion());
			System.out.println("");			
		}

		
	}
}