package logica.partida;

import logica.valueObjects.VoPartida;
import logica.valueObjects.VoPartidaEnCurso;

public class Partida 
{
	
	private int nroPartida;
	
	private int nroSecreto;
	
	private boolean finalizada;
	
	private int cantidadIntentos;
	
	private int puntajeFinal;
	
	public Partida(int nroPartida,int nroSecreto)
	{
		this.nroPartida = nroPartida;
		this.nroSecreto = nroSecreto;
		finalizada = false;
		cantidadIntentos = 0;
		puntajeFinal = 0;
	}

	public boolean isFinalizada() 
	{
		return finalizada;
	}

	public void setFinalizada(boolean finalizada) 
	{
		this.finalizada = finalizada;
	}

	public int getCantidadIntentos() 
	{
		return cantidadIntentos;
	}

	public void setCantidadIntentos(int cantidadIntentos) 
	{
		this.cantidadIntentos = cantidadIntentos;
	}

	public int getPuntajeFinal() 
	{
		return puntajeFinal;
	}

	public void setPuntajeFinal(int puntajeFinal) 
	{
		this.puntajeFinal = puntajeFinal;
	}

	public int getNroPartida() 
	{
		return nroPartida;
	}

	public int getNroSecreto() 
	{
		return nroSecreto;
	}
	
	public VoPartida getVOPartida()
	{
		VoPartida voP = new VoPartida(nroPartida, finalizada,cantidadIntentos, puntajeFinal,nroSecreto);
		return voP;
	}
	
	public VoPartidaEnCurso getVOPartidaCurso()
	{
		VoPartidaEnCurso voPartidaEnCurso = new VoPartidaEnCurso(nroPartida, finalizada,cantidadIntentos, puntajeFinal);
		return voPartidaEnCurso;
	}
	
	public int calcularPuntaje()
	{
		return (1000 / cantidadIntentos);
	}
	
}
