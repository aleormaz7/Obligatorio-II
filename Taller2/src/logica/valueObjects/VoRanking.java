package logica.valueObjects;

public class VoRanking extends VoJugador 
{
	private int posicion;
	
	public VoRanking(String nombre, int puntaje, int cantPartidasFinalizadas, int cociente,int posicion)
	{
		super(nombre, puntaje, cantPartidasFinalizadas, cociente);
		this.posicion = posicion;
	}

	public int getPosicion() 
	{
		return posicion;
	}
	
	public void setPosicion(int pos) 
	{
		this.posicion = pos;
	}


}
