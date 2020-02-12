package logica.valueObjects;

public class VoJugador 
{
	private String nombre;
	
	private int puntaje;
	
	private int cantPartidasFinalizadas;
	
	private int cociente;
	
	public VoJugador(String nombre,int puntaje,int cantPartidasFinalizadas,int cociente)
	{
		this.nombre = nombre;
		this.puntaje = puntaje;
		this.cantPartidasFinalizadas = cantPartidasFinalizadas;
		this.cociente = cociente;
	}

	public String getNombre() 
	{
		return nombre;
	}

	public int getPuntaje() 
	{
		return puntaje;
	}

	public int getCantPartidasFinalizadas() 
	{
		return cantPartidasFinalizadas;
	}

	public int getCociente() 
	{
		return cociente;
	}
	

}
