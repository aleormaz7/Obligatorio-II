package logica.valueObjects;

public class VoPartida extends VoPartidaEnCurso 
{
	
	private int nroSecreto;
	
	public VoPartida(int nroPartida, boolean finalizada, int cantIntentosRealizados, int puntajeObtenido,int nroSecreto) 
	{
		super(nroPartida, finalizada, cantIntentosRealizados, puntajeObtenido);
		
		this.nroSecreto = nroSecreto;
	}

	public int getNroSecreto() 
	{
		return nroSecreto;
	}
	
	

}
