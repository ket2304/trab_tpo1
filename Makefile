# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

# Nome do executável final
TARGET = hotel.exe

# Todos os arquivos fonte (.cpp)
SRC = main.cpp \
      Gerente.cpp \
      Hospede.cpp \
      Hotel.cpp \
      Pessoa.cpp \
      Quarto.cpp \
      Reserva.cpp


# Regra principal
all: $(TARGET)

# Como gerar o executável
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LIBS) -o $(TARGET)

# Executar o programa
run: $(TARGET)
	./$(TARGET)

# Limpar arquivos compilados
clean:
	del /Q $(TARGET)
