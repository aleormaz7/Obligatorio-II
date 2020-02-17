package logica.jugador;


import logica.partida.Partida;
import logica.partida.Partidas;
import logica.valueObjects.VoJugadorGeneral;
import logica.valueObjects.VoPartida;
import logica.valueObjects.VoRanking;

public class Jugador 
{
	private String nombre;
	
	private String codigoIngreso;
	
	private int puntajeTotal;
	
	private int cantidadPartidasFinalizadas;
	
	private int cociente;

	private Partidas secuenciaPartidas;
	
	public Jugador(String nombre, String codigoIngreso)
	{
		this.nombre = nombre;
		this.codigoIngreso = codigoIngreso;
		this.puntajeTotal = 0;
		this.cantidadPartidasFinalizadas = 0;
		this.cociente = 0;
		this.secuenciaPartidas = new Partidas();
	}

	public String getNombre() 
	{
		return nombre;
	}

	public void setNombre(String nombre) 
	{
		this.nombre = nombre;
	}

	public int getPuntajeTotal() 
	{
		return puntajeTotal;
	}

	public void setPuntajeTotal(int puntajeTotal) 
	{
		this.puntajeTotal = puntajeTotal;
	}

	public int getCantidadPartidasFinalizadas() 
	{
		return cantidadPartidasFinalizadas;
	}

	public void setCantidadPartidasFinalizadas(int cantidadPartidasFinalizadas) 
	{
		this.cantidadPartidasFinalizadas = cantidadPartidasFinalizadas;
	}

	public int getCociente() 
	{
		return cociente;
	}

	public void setCociente(int coeficiente) 
	{
		this.cociente = coeficiente;
	}

	public String getCodigoIngreso() 
	{
		return codigoIngreso;
	}
	
	public void registrarPartida()
	{		
		int nroSecreto = 100;//(int) Math.floor(Math.random()*(1-1000+1)+1000);
		
		Partida p = new Partida(secuenciaPartidas.largo()+1,nroSecreto);
		secuenciaPartidas.insBack(p);
	}
	
	public VoPartida[] listarPartidas()
	{			
		VoPartida[] arrayPartidas = secuenciaPartidas.listarPartidas();
		return arrayPartidas;
	}
	
	public VoPartida[] listarPartidaEnCurso()
	{		
		VoPartida[] arrayPartidas = null;
		if(!secuenciaPartidas.ultimo().isFinalizada())
		{
			arrayPartidas = secuenciaPartidas.listarPartidas();
		}
		return arrayPartidas;
	}
	
	public boolean hayPartidas()
	{
		if(secuenciaPartidas.largo()>0)
			return true;
		else
			return false;
	}
		 	 
	public Partida hayUltimaPartida()
	{
		return secuenciaPartidas.ultimo(); 
	}	
	
	public boolean hayPartidaEnCurso()
	{
		return secuenciaPartidas.ultimo().isFinalizada(); 
	}
	
	public VoJugadorGeneral getVoJugadorGeneral() 
	{
		VoJugadorGeneral VoJugGen = new VoJugadorGeneral(nombre, puntajeTotal, cantidadPartidasFinalizadas, cociente, codigoIngreso);
		return VoJugGen;
	}
	 	
	public VoRanking getVoRanking(int pos)
	{
		VoRanking VoRankJug = new VoRanking(nombre, puntajeTotal, cantidadPartidasFinalizadas, cociente, pos);
		return VoRankJug;
	}
	 
}
