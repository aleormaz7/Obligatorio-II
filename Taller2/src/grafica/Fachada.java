package grafica;

import java.util.Collection;
import java.util.Iterator;

import excepciones.JugadorCodigoIncorrectoException;
import excepciones.JugadorExisteException;
import excepciones.NoHayPartidaDisponibleException;
import excepciones.PartidaEnCursoException;
import excepciones.PartidaFinalizadaException;
import logica.enumerados.EResultado;
import logica.jugador.Jugador;
import logica.jugador.Jugadores;
import logica.partida.Partida;
import logica.partida.Partidas;
import logica.valueObjects.VoJugadorGeneral;
import logica.valueObjects.VoPartida;
import logica.valueObjects.VoPartidaEnCurso;
import logica.valueObjects.VoRanking;

public class Fachada 
{
	public Jugadores jugadores;
	
	
	public Fachada()
	{
		jugadores = new Jugadores();
		
	}
	
	public void registrarNuevoJugador(String nom ,String cod) throws JugadorExisteException 
	{
		if(jugadores.member(nom))
		{			
			throw new JugadorExisteException("Jugador ya existe!!");	
		}
		else
		{
			
			Jugador j = new Jugador(nom,cod);
			jugadores.insert(j);			
		}
		
	}
	
	public VoJugadorGeneral[] listarJuagadores()
	{		
		return jugadores.listarJugadores();
	}
	
	

	public void iniciarNuevaPartida(String nom,String cod) throws JugadorExisteException,JugadorCodigoIncorrectoException,PartidaEnCursoException
	{
		if(!jugadores.member(nom))
		{			
			throw new JugadorExisteException("Jugador No existe!!");	
		}
		else
		{
			Jugador j = jugadores.find(nom);
			if(j.getCodigoIngreso() != cod)
			{
				throw new JugadorCodigoIncorrectoException("Codigo Ingreso Incorrecto!!");
			}
			else
			{
				///..PRECONDICION..??..SUBDIVIDIR SINO PONGO j.hayPartidas() rompe........??
				if(j.hayPartidas() && j.hayPartidaEnCurso() == true)
				{
					throw new PartidaEnCursoException("Ya hay partida en curso!!");
				}
				else 
				{	
					j.registrarPartida();
				}
			}
		}
		
	}
	
	public VoPartida[] listarPartidasJuagador(String nom) throws JugadorExisteException
	{
		if(!jugadores.member(nom))
		{
			throw new JugadorExisteException("Jugador no existe!!");						
		}
		else
		{			
			Jugador j = jugadores.find(nom);
			VoPartida[] secP = j.listarPartidas();
			return secP;
		}		
	}
	
	public void login(String nom,String cod) throws JugadorExisteException, JugadorCodigoIncorrectoException
	{
		if(!jugadores.member(nom))
		{
			throw new JugadorExisteException("Jugador no existe!!");
		}
		else
		{
			Jugador j = jugadores.find(nom);
			if(j.getCodigoIngreso() != cod)
			{
				throw new JugadorCodigoIncorrectoException("Codigo Ingreso Incorrecto!!");
			}
			else
			{
				//??......ACA QUE DEVOLVER, UN BOOLEANO EN LA FUNCION..............................??
				System.out.println("Jugador Se logueo con exito!!");
			}
		}
		
	}
	
	public VoPartidaEnCurso visualizarPartidaEnCurso(String nom,String cod) throws JugadorExisteException, JugadorCodigoIncorrectoException,NoHayPartidaDisponibleException
	{
		if(!jugadores.member(nom))
		{
			throw new JugadorExisteException("Jugador no existe!!");		
		}
		else
		{
			Jugador j = jugadores.find(nom);
			if(j.getCodigoIngreso() != cod)
			{
				throw new JugadorCodigoIncorrectoException("Codigo Ingreso Incorrecto!!");
			}
			else
			{
				//??....ACA SERIA, SI HAY PARTIDAS Y ADEMAS LA ULTIMA ESTA EN CURSO....??
				if(!j.hayPartidas())
				{
					throw new NoHayPartidaDisponibleException("No Hay Partidas Disponibles");
				}
				else
				{
					Partida p = j.hayUltimaPartida();
					VoPartidaEnCurso VoPartEnCurso = new VoPartidaEnCurso(p.getNroPartida(),p.isFinalizada(),p.getCantidadIntentos(),p.getPuntajeFinal());
					return VoPartEnCurso;
				}
			}
		}	
	}
	
	
	public EResultado realizarIntento(String nom,String cod,int numero) throws JugadorExisteException, JugadorCodigoIncorrectoException,NoHayPartidaDisponibleException,PartidaFinalizadaException
	{		
		EResultado resu = null;
		if(!jugadores.member(nom))
		{
			throw new JugadorExisteException("Jugador no existe!!");		
		}
		else
		{
			Jugador j = jugadores.find(nom);
			if(j.getCodigoIngreso() != cod)
			{
				throw new JugadorCodigoIncorrectoException("Codigo Ingreso Incorrecto!!");
			}
			else
			{
				if(!j.hayPartidas())
				{
					throw new NoHayPartidaDisponibleException("No Hay Partidas Disponibles");
				}
				else
				{ 
					if(j.hayUltimaPartida().isFinalizada() == true)
					{
						throw new PartidaFinalizadaException("Partida se encuentra finalizada");
					}
					else
					{
						Partida ultP = j.hayUltimaPartida();
						ultP.setCantidadIntentos(ultP.getCantidadIntentos()+1);
						int numSecreto = ultP.getNroSecreto();
						/*switch(numero)
						{
							case numero == numSecreto:......................??
						}*/
						
						if(numero == numSecreto)
						{
							ultP.setFinalizada(true);
							int puntaje = ultP.calcularPuntaje();
							j.setPuntajeTotal(j.getPuntajeTotal() + puntaje);
							j.setCantidadPartidasFinalizadas(j.getCantidadPartidasFinalizadas()+1);							
							int cociente = (j.getPuntajeTotal() / j.getCantidadPartidasFinalizadas());
							j.setCociente(cociente);
							resu = EResultado.ACIERTO;
						}
						else if(numero > numSecreto)
						{
							resu = EResultado.MAYOR;
						}
						else if(numero < numSecreto)
						{
							resu = EResultado.MENOR;
						}
					}
				}
			}
		}	
		
		return resu;
	}
	
	
	public void aboandonarPartida(String nom,String cod) throws JugadorExisteException, JugadorCodigoIncorrectoException,NoHayPartidaDisponibleException,PartidaFinalizadaException 
	{
		if(!jugadores.member(nom))
		{
			throw new JugadorExisteException("Jugador no existe!!");		
		}
		else
		{
			Jugador j = jugadores.find(nom);
			if(j.getCodigoIngreso() != cod)
			{
				throw new JugadorCodigoIncorrectoException("Codigo Ingreso Incorrecto!!");
			}
			else
			{
				if(!j.hayPartidas())
				{
					throw new NoHayPartidaDisponibleException("No Hay Partidas Disponibles");
				}
				else
				{ 
					if(j.hayUltimaPartida().isFinalizada() == true)
					{
						throw new PartidaFinalizadaException("Partida se encuentra finalizada");
					}
					else
					{
						Partida ultP = j.hayUltimaPartida();
						j.setCantidadPartidasFinalizadas(j.getCantidadPartidasFinalizadas()+1);
						ultP.setPuntajeFinal(0);
						j.setCociente(0);					
					}
				}
			}
		}
	}
	
	
	public VoRanking[] rankingGlobal()
	{
		
		VoRanking[] voRank = new VoRanking[jugadores.largo()];
		
		//voRank = 
		//PARA CADA JUGADOR DEL ARBOL AGREGARLO AL LISTADO ORDENADO POR COCIENTE
		
		return voRank;

		
	}

	
	
}
