package logica.valueObjects;

public class VoJugadorGeneral extends VoJugador
{
	private String codigoIngreso;

	public VoJugadorGeneral(String nombre, int puntaje, int cantPartidasFinalizadas, int cociente,String codigoIngreso)
	{
		super(nombre, puntaje, cantPartidasFinalizadas, cociente);
		
		this.codigoIngreso = codigoIngreso;
	}

	public String getCodigoIngreso() 
	{
		return codigoIngreso;
	}
	

}
