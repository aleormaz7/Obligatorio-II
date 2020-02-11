package logica.Partida;

public class Partida {
	
	private int nroPartida;
	
	private int nroSecreto;
	
	private boolean finalizada;
	
	private int cantidadIntentos;
	
	private int puntajeFinal;

	public boolean isFinalizada() {
		return finalizada;
	}

	public void setFinalizada(boolean finalizada) {
		this.finalizada = finalizada;
	}

	public int getCantidadIntentos() {
		return cantidadIntentos;
	}

	public void setCantidadIntentos(int cantidadIntentos) {
		this.cantidadIntentos = cantidadIntentos;
	}

	public int getPuntajeFinal() {
		return puntajeFinal;
	}

	public void setPuntajeFinal(int puntajeFinal) {
		this.puntajeFinal = puntajeFinal;
	}

	public int getNroPartida() {
		return nroPartida;
	}

	public int getNroSecreto() {
		return nroSecreto;
	}
	

}
