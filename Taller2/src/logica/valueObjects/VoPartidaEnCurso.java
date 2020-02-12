package logica.valueObjects;

public class VoPartidaEnCurso 
{
	private int nroPartida;
	
	private boolean finalizada;
	
	private int cantIntentosRealizados;
	
	private int puntajeObtenido;
	
	public VoPartidaEnCurso(int nroPartida,boolean finalizada,int cantIntentosRealizados,int puntajeObtenido)
	{
		this.nroPartida = nroPartida;
		this.finalizada = finalizada;
		this.cantIntentosRealizados = cantIntentosRealizados;
		this.puntajeObtenido = puntajeObtenido;
		
	}

	public int getNroPartida() 
	{
		return nroPartida;
	}

	public boolean isFinalizada() 
	{
		return finalizada;
	}

	public int getCantIntentosRealizados() 
	{
		return cantIntentosRealizados;
	}

	public int getPuntajeObtenido() 
	{
		return puntajeObtenido;
	}
	
	

}
