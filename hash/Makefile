# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
LDFLAGS = -lcryptopp

# Имя исполняемого файла
TARGET = filehasher

# Исходные файлы
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Компиляция объектных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(TARGET) $(OBJECTS)

# Установка (если требуется)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Тестирование
test: $(TARGET)
	@echo "=== Тестирование программы ==="
	@echo "Создание тестового файла..."
	@echo "Hello, Crypto++!" > test.txt
	@./$(TARGET) test.txt
	@echo "Ожидаемый результат можно проверить командой: sha256sum test.txt"
	@rm -f test.txt

.PHONY: all clean install test