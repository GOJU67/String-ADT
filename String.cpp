#include"String.h"
bool String::isValidIndex(const int index) const
{
	return (index >= 0 && index < size);
}
void String::mySwap(char* a, char* b)
{
	if (isNullPtr(a) || isNullCharacter(a[0]) || isNullPtr(b) || isNullCharacter(b[0]))
	{
		return;
	}
	char temp = *a;
	*a = *b;
	*b = temp;
}
int String::giveResultOfComparingGivenStringsIndexValue(const char str1,const char str2)
{
	if (str1<str2)
	{
		return -1;
	}
	else if (str1>str2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool String::isStringNegative() const
{
	if (isEmpty() )
	{
		return false;
	}
	if (data[0] == '-')
	{
		return true;
	}
	return false;
}
bool String::isStringPositive() const
{
	if (isEmpty() )
	{
		return false;
	}
	if (data[0] == '+')
	{
		return true;
	}
	return false;
}
int String::giveNumberLength(long long int a)
{
	int length = 0;
	if (a==0)
	{
		length = 1;
	}
	else
	{
		if (a<0)
		{
			length++;
			a = a * -1;
		}
		while (a>0)
		{
			length++;
			a = a / 10;
		}
	}
	return length;
}
int String::giveLengthOfGivenString(const char* temp)
{
	if (isNullPtr(temp) || isNullCharacter(temp[0]))
	{
		return 0;
	}
	int count = 0;
	while (temp[count] != '\0')
	{
		count++;
	}
	return count;
}
bool String::isNullPtr(const char* pointer)
{
	return (pointer == nullptr);
}
bool String::isNullCharacter(const char character)
{
	return (character == '\0');
}
void String::createString(char*& string, const int size)
{
	string = new char[size];
}
void String::copyString(char* dest, const char* sour)
{
	if (isNullPtr(dest))
	{
		return;
	}
	if (isNullPtr(sour))
	{
		delete[]dest;
		dest = nullptr;
		return;
	}
	int count = 0;
	while (sour[count] != '\0')
	{
		dest[count] = sour[count];
		count++;
	}
	dest[count] = '\0';
}
void String::copyStringByUsingLength(char* dest, const char* sour, const int sizeOfSource)
{
	if (sizeOfSource <= 0)
	{
		dest = nullptr;
		return;
	}
	if (isNullPtr(dest))
	{
		return;
	}
	if (isNullPtr(sour))
	{
		delete[]dest;
		dest = nullptr;
		return;
	}
	int count = 0;
	while (count < sizeOfSource - 1)
	{
		dest[count] = sour[count];
		count++;
	}
	dest[count] = '\0';
}








String::String()
{
	data = nullptr;
	size = 0;
}
String::String(const String & ref) : String()
{
	if ( ref.isEmpty() )
	{
		return;
	}
	size = ref.size;
	createString(data, size);
	copyStringByUsingLength(data, ref.data, ref.size);
}
String::String(String&& ref) noexcept : String()
{
	if (ref.isEmpty() || ref.size <= 0 )
	{
		return;
	}
	data = ref.data;
	size = ref.size;
	ref.data = nullptr;
	ref.size = 0;
}
String::String(unsigned int count, ...) : String()
{
	va_list vl;
	__crt_va_start(vl, count);
	String temp = __crt_va_arg(vl, const char*);
	size = (giveLengthOfGivenString(temp.data) + 1);
	createString(data, size);
	copyString(data, temp.data);
	for (unsigned int i = 0; i < (count - 1); i++)
	{
		String temp = __crt_va_arg(vl, const char*);
		concatEqual(temp);
	}
	__crt_va_end(vl);
}
String::String(const char c) : String()
{
	if ( isNullCharacter(c) )
	{
		size = 1;
		createString(data, size);
		data[0] = '\0';
		return;
	}
	size = 2;
	createString(data, size);
	data[0] = c;
	data[1] = '\0';
}
String::String(const char* temp) : String()
{
	if (isNullPtr(temp) )
	{
		return;
	}
	size = (giveLengthOfGivenString(temp) + 1);
	createString(data, size);
	copyString(data, temp);
}
String::String(const long long int a)
{
	long long int temp = a;
	size = (giveNumberLength(temp) + 1);
	createString(data, (size));
	if (a == 0)
	{
		data[0] = '0';
		data[1] = '\0';
	}
	else
	{
		temp = a;
		if (a < 0)
		{
			data[size - 2] = '-';
			temp = temp * -1;
			for (int i = 0; i < size - 2; i++)
			{
				data[i] = '0' + (temp % 10);
				temp = temp / 10;
			}
		}
		else
		{
			for (int i = 0; i < size - 1; i++)
			{
				data[i] = '0' + (temp % 10);
				temp = temp / 10;
			}

		}
		data[size - 1] = '\0';
		reverse();
	}
}
void String::input()
{
	if (!isNullPtr(data))
	{
		this->~String();
	}
	char character;
	int count = 0,length=0;
	size = 2;
	createString(data, size);
	while (cin.get(character)&&character!='\n')
	{
		if (count==size-1)
		{
			length=size+1;
			reSize(length);
		}
		data[count] = character;
		count++;
	}
	data[count] = '\0';
}
void String::reSize(const int newSize)
{
	if (size==newSize)
	{
		return;
	}
	if (newSize<=0)
	{
		this->~String();
		return;
	}
	int limit = (newSize < size) ? newSize : size;
	char* temp;
	createString(temp, newSize);
	copyStringByUsingLength(temp, data, limit);
	this->~String();
	data = temp;
	size = newSize;
}
void String::display() const
{
	if (isEmpty() )
	{
		return;
	}
	cout << data;
}
char& String::at(const int index)
{
	if (!isEmpty() && isValidIndex(index))
	{
		return data[index];
	}
	else
	{
		exit(0);
	}
}
const char& String::at(const int index) const
{
	if (!isEmpty() && isValidIndex(index))
	{
		return data[index];
	}
	else
	{
		exit(0);
	}
}
String::~String()
{
	if (isNullPtr(data))
	{
		return;
	}
	delete[]data;
	data = nullptr;
	size = 0;
}
bool String::isEmpty() const
{
	return (isNullPtr(data) || isNullCharacter(data[0]));
}
int String::getLength() const
{
	if (isEmpty())
	{
		return 0;
	}
	return giveLengthOfGivenString(data);
}
int String::getSize() const
{
	return size;
}
int String::find(const String& subStr, const int start) const
{
	if (!isValidIndex(start))
	{
		return -1;
	}
	if (size < subStr.getSize())
	{
		return -1;
	}
	if (isEmpty() || subStr.isEmpty())
	{
		return -1;
	}
	int length=subStr.getLength();
	for (int i = start; i <= size-length; i++)
	{
		int result = 0;
		for (int j = 0; j < length; j++)
		{
			if (data[i+j]==subStr.data[j])
			{
				result++;
			}
		}
		if (result==length)
		{
			return i;
		}
	}
	return -1;
}
void String::insert(const int index, const String& subStr)
{
	if (isEmpty() || isNullPtr(subStr.data) || !isValidIndex(index))
	{
		return;
	}
	if (size >= (getLength() + subStr.getLength() + 1))
	{
		char* temp;
		createString(temp, (getLength() + 1));
		copyStringByUsingLength(temp, data, (getLength() + 1));
		copyString(&data[index], subStr.data);
		copyString(&data[index + subStr.getLength()], &temp[index]);
		delete[]temp;
		temp = nullptr;
	}
	else
	{
		char* temp;
		int newSize = getLength() + subStr.getSize() + 1;
		createString(temp, newSize);
		copyStringByUsingLength(temp, data, (index + 1));
		copyString(&temp[index], subStr.data);
		copyString(&temp[index + subStr.getLength()], &data[index]);
		this->~String();
		data = temp;
		size = newSize;
	}
}
void String::remove(const int index, const int count)
{
	if (isEmpty() || !isValidIndex(index) || !isValidIndex(index + count) )
	{
		return;
	}
	copyString(&data[index], &data[index + count]);
}
int String::replace(const String& old, const String& newSubStr)
{
	if (isEmpty() || old.isEmpty() || newSubStr.isEmpty())
	{
		return 0;
	}
	int count = 0, index = 0;
	while ( (index = find(old, index) ) && index != -1)
	{
		remove(index, old.getLength());
		insert(index, newSubStr);
		index = index + newSubStr.getLength();
		count++;
	}
	return count;
}
void String::trimLeft()
{
	if (isEmpty())
	{
		return;
	}
	int count = 0, index = 0;
	while (data[index] == ' ' || data[index] == '\t' || data[index] == '\n')
	{
		count++;
		index++;
	}
	remove(0, count);
	//size = size - count;
}
void String::trimRight()
{
	if (isEmpty())
	{
		return;
	}
	int count = 0, index = (getLength()-1);
	while (index>=0 && data[index] == ' ' || data[index] == '\t' || data[index] == '\n')
	{
		count++;
		index--;
	}
	data[getLength() - count] = '\0';
	//size = size - count;
}
void String::trim()
{
	if (isEmpty())
	{
		return;
	}
	trimLeft();
	trimRight();
}
void String::makeUpper()
{
	if (isEmpty())
	{
		return;
	}
	for (int i = 0; data[i] != '\0'; i++)
	{
		if (data[i]>='a'&&data[i]<='z')
		{
			data[i] = data[i] - 32;
		}
	}
}
void String::makeLower()
{
	if (isEmpty())
	{
		return;
	}
	for (int i = 0; data[i] != '\0'; i++)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + 32;
		}
	}
}
void String::reverse()
{
	if (isEmpty())
	{
		return;
	}
	for (int i = 0,j = getLength()-1; i < j; i++,j--)
	{
		mySwap(&data[i], &data[j]);
	}
}
void String::shrink()
{
	if (isEmpty())
	{
		return;
	}
	reSize(getLength() + 1);
} 
int String::compare(const String& s2) const
{
	if ( isEmpty() && s2.isEmpty() )
	{
		return 0;
	}
	if (isEmpty() && !s2.isEmpty())
	{
		return -1;
	}
	if (!isEmpty() && s2.isEmpty())
	{
		return 1;
	}
	int index = 0;
	while (!isNullCharacter(data[index]) && !isNullCharacter(s2.data[index]) && data[index] == s2.data[index])
	{
		index++;
	}
	return giveResultOfComparingGivenStringsIndexValue(data[index], s2.data[index]);
}
String String::left(const int count)
{
	if (isEmpty() || !isValidIndex(count))
	{
		return *this;
	}
	String a;
	a.size = count + 1;
	createString(a.data, a.size);
	copyStringByUsingLength(a.data, data, a.size);
	remove(0, count);
	return a;
}
String String::right(const int count)
{
	if (isEmpty() || !isValidIndex(count))
	{
		return *this;
	}
	String a;
	a.size = count + 1;
	createString(a.data, a.size);
	copyStringByUsingLength(a.data, &data[getLength() - count], a.size);
	remove((getLength() - count), count);
	return a;
}
long long int String::convertToInteger() const
{
	if (isEmpty())
	{
		return 0;
	}
	int index = 0;
	int sign = 1;
	if (isStringNegative())
	{
		sign = -1;
		index = 1;
	}
	if (isStringPositive())
	{
		index = 1;
	}
	long long int number = 0;
	for (int i = index; data[i]!='\0'; i++)
	{
		if (data[i]>='0'&&data[i]<='9')
		{
			number = number * 10;
			number = number + (data[i] - '0');
		}
		else
		{
			return number*sign;
		}
	}
	return number*sign;
}
float String::convertToFloat() const
{
	if (isEmpty())
	{
		return 0.0;
	}
	int index1 = 0, index2 = 0,length=0;
	float sign = 1.0;
	if (isStringNegative())
	{
		sign = -1.0;
		index1 = 1;
	}
	if (isStringPositive())
	{
		index1 = 1;
	}
	bool alreadyFind = false;
	float num=0.0;
	for (int i = index1; data[i] != '\0'; i++)
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			num = num * 10;
			num = num + (data[i] - '0');
			length++;
			//cout << num << "\n";
		}
		else if (data[i]=='.' && !alreadyFind)
		{
			index2 = i;
			alreadyFind = true;
		}
		else
		{
			if (alreadyFind)
			{
				for (int j = 0; j < (length - index2); j++)
				{
					num = num / 10;
				}
			}
			return num * sign;
		}
	}
	if (alreadyFind)
	{
		for (int j = 0; j < (length - index2); j++)
		{
			num = num / 10;
		}
	}
	return num * sign;
}
String String::concatenate(const String& s2) const
{
	if (isEmpty() || s2.isEmpty())
	{
		return *this;
	}
	String a;
	a.size = size + s2.size;
	createString(a.data, a.size);
	copyStringByUsingLength(a.data, data, size);
	copyStringByUsingLength(&a.data[size - 1], s2.data, s2.size);
	return a;
}
void String::concatEqual(const String& s2)
{
	if (isEmpty() || s2.isEmpty())
	{
		return;
	}
	insert(getLength(), s2);
}
void String::setNumber(const long long int a)
{
	if (!isEmpty())
	{
		this->~String();
	}
	long long int temp =a;
	size = (giveNumberLength(temp) + 1);
	createString(data, (size));
	if (a == 0)
	{
		data[0] = '0';
		data[1] = '\0';
	}
	else
	{
		if (a < 0)
		{
			data[size - 2] = '-';
			temp = temp * -1;
			for (int i = 0; i < size - 2; i++)
			{
				data[i] = '0' + (temp % 10);
				temp = temp / 10;
			}
		}
		else
		{
			for (int i = 0; i < size - 1; i++)
			{
				data[i] = '0' + (temp % 10);
				temp = temp / 10;
			}

		}
		data[size - 1] = '\0';
		reverse();
	}
}
String	String::operator +(const String & s2) const
{
	if (isEmpty() || s2.isEmpty())
	{
		return *this;
	}
	String temp{ *this };
	temp.concatEqual(s2);
	return temp;
}
void String::operator +=(const String& s2)
{
	if (isNullPtr(s2.data) == true || isNullCharacter(s2.data[0]) == true)
	{
		return ;
	}
	this->concatEqual(s2);
}
void String::operator()(const int count, ...)
{
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true)
	{
		return;
	}
	if (count==0)
	{
		return;
	}
	va_list listOfCount;
	__crt_va_start(listOfCount, count);
	char* temporary = nullptr;
	for (int i = 0; i < count; i++)
	{
		String temp(__crt_va_arg(listOfCount, char*));
		while (find(temp) != -1)
		{
			remove(find(temp), temp.getLength());
		}
	}
	__crt_va_end(listOfCount);
}
String& String::operator =(const long long int a)
{
	setNumber(a);
	return*this;
}
int String::operator ==(const String& s2) const
{
	return compare(s2);
}
String String::operator -(const String& s2) const
{
	if (isEmpty() || s2.isEmpty())
	{
		return *this;
	}
	String temp{*this};
	while (temp.find(s2) != -1)
	{
		temp.remove(temp.find(s2), s2.getLength());
	}
	return temp;
}
String& String::operator = (const String& s2)
{
	if (compare(s2)==0)
	{
		return *this;
	}
	if (s2.isEmpty()|| s2.size <= 0)
	{
		this->~String();
		return *this;
	}
	if (!isEmpty()|| size > 0)
	{
		this->~String();
	}
	size = s2.size;
	createString(data, size);
	copyStringByUsingLength(data, s2.data, s2.size);
	return *this;
}
bool String::operator >(const String& s2) const
{
	if (compare(s2) == 1)
	{
		return 1;
	}
	return 0;
}
bool String::operator <(const String& s2) const
{
	if (compare(s2) == -1)
	{
		return 1;
	}
	return 0;
}
bool String::operator <=(const String& s2) const
{
	if (( *this < s2 ) || ( *this == s2 ) == 0)
	{
		return 1;
	}
	return 0;
}
bool String::operator >=(const String& s2) const
{
	if ((*this == s2) == 0|| (*this > s2))
	{
		return 1;
	}
	return 0;
}
bool String::operator !=(const String& s2) const
{
	if ((*this == s2) != 0)
	{
		return 1;
	}
	return 0;
}
istream & operator>>( istream& s1,String& s2)
{
	if (!s2.isEmpty())
	{
		s2.~String();
	}
	s2.input();
	return s1;
}
ostream& operator<<(ostream& s1, const String& s2)
{
	if (s2.isEmpty())
	{
		return s1;
	}
	s1 << s2.data;
	return s1;
}
void String::concatEqual(const long long int num)
{
	String temp(num);
	if (isNullPtr(data) == true || isNullCharacter(data[0]) == true || isNullPtr(temp.data) == true || isNullCharacter(temp.data[0]) == true)
	{
		return;
	}
	int length = temp.getLength();
	reSize(size + temp.getLength());
	copyStringByUsingLength(&data[getLength()], temp.data, temp.getSize());
}
void String::operator -=(const String& s2)
{
	if (isEmpty() || s2.isEmpty())
	{
		return;
	}
	remove(find(s2), s2.getLength());
}
char& String::operator [](const int a)
{
	if (!isNullPtr(data)&& !isNullCharacter(data[0])&& isValidIndex(a))
	{
		return data[a];
	}
	exit(0);
}
const char& String::operator [](const int a) const
{
	if (!isNullPtr(data) && !isNullCharacter(data[0]) && isValidIndex(a))
	{
		return data[a];
	}
	exit(0);
}
void String::concatAll(const unsigned int count, ...)
{
	if (count == 0)
	{
		return;
	}
	if (isEmpty())
	{
		return;
	}
	va_list listOfCount;
	__crt_va_start(listOfCount, count);
	for (unsigned int i = 0; i < count; i++)
	{
		String temp(__crt_va_arg(listOfCount, char*));
		concatEqual(temp);
	}
	__crt_va_end(listOfCount);
}
String& String::operator = (String&& s2) noexcept
{
	if (s2.isEmpty() || s2.size <= 0)
	{
		return *this;
	}
	data = s2.data;
	size = s2.size;
	s2.data = nullptr;
	s2.size = 0;
	return *this;
}
void String::mySwap(String& a, String& b)
{
	if ((a==b)==0)
	{
		return;
	}
	String temp = move(a);
	a = move(b);
	b = move(temp);
}
bool String::operator ! () const
{
	return isEmpty();
}
String::operator long long int() const
{
	return convertToInteger();
}
double String::convertToDouble() const
{
	if (isEmpty())
	{
		return 0.0;
	}
	int index1 = 0, index2 = 0, length = 0;
	double sign = 1.0;
	if (isStringNegative())
	{
		sign = -1.0;
		index1 = 1;
	}
	if (isStringPositive())
	{
		index1 = 1;
	}
	bool alreadyFind = false;
	double num = 0.0;
	for (int i = index1; data[i] != '\0'; i++)
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			num = num * 10;
			num = num + (data[i] - '0');
			length++;
		}
		else if (data[i] == '.' && !alreadyFind)
		{
			index2 = i;
			alreadyFind = true;
		}
		else
		{
			if (alreadyFind)
			{
				for (int j = 0; j < (length - index2); j++)
				{
					num = num / 10;
				}
			}
			return num * sign;
		}
	}
	if (alreadyFind)
	{
		for (int j = 0; j < (length - index2); j++)
		{
			num = num / 10;
		}
	}
	return num * sign;
}
void String::roundFraction(int* fracDigits, int& integerPart, bool isNegative) 
{
	if (fracDigits[12] >= 5) 
	{
		fracDigits[11]++;
		for (int j = 11; j > 0; j--) 
		{
			if (fracDigits[j] == 10) 
			{
				fracDigits[j] = 0;
				fracDigits[j - 1]++;
			}
		}
		if (fracDigits[0] == 10) 
		{
			fracDigits[0] = 0;
			if (isNegative) 
			{
				integerPart--;
			}
			else 
			{
				integerPart++;
			}
		}
	}
}
int String::convertIntegerPart(int integerPart, bool isNegative) 
{
	int index = 0;
	if (isNegative) 
	{
		data[index++] = '-';
	}
	if (integerPart == 0) 
	{
		data[index++] = '0';
	}
	else 
	{
		int temp = integerPart;
		int intDigits[20];
		int count = 0;
		while (temp > 0) 
		{
			intDigits[count++] = temp % 10;
			temp /= 10;
		}
		for (int j = count - 1; j >= 0; --j) 
		{
			data[index++] = intDigits[j] + '0';
		}
	}
	return index;
}
int String::convertFractionalPart(double fractionalPart, int start) 
{
	int fracDigits[13];
	for (int j = 0; j < 13; j++) 
	{
		fractionalPart *= 10;
		fracDigits[j] = (int)fractionalPart;
		fractionalPart -= fracDigits[j];
	}
	roundFraction(fracDigits, start, data[0] == '-');
	for (int j = 0; j < 12; j++) 
	{
		data[start++] = fracDigits[j] + '0';
	}
	while (start > 1 && data[start - 1] == '0') 
	{
		--start;
	}
	if (data[start - 1] == '.') 
	{
		--start;
	}
	return start;
}
String& String::operator = (const double num)
{
	if (!(!*this))
	{
		this->~String();
	}
	size = 200;
	createString(data, size);
	int integerPart = (int)num;
	double fractionalPart = num - integerPart;
	bool isNegative = num < 0;
	if (isNegative) 
	{
		integerPart = integerPart * -1;
		fractionalPart = fractionalPart * -1;
	}
	int i = convertIntegerPart(integerPart, isNegative);
	data[i++] = '.';
	i = convertFractionalPart(fractionalPart, i);
	data[i] = '\0';
	return *this;
}
String::operator bool() const
{
	return !isEmpty();
}
String::operator double() const
{
	return convertToDouble();
}
bool String::isDelimiter(char c, const String& delim) const
{
	if (!delim)
	{
		return false;
	}
	for (int i = 0; i < delim.getLength(); i++) 
	{
		if (c == delim[i]) 
		{
			return true;
		}
	}
	return false;
}
String String::operator () (const String& delim) 
{
	if (!*this || !delim) 
	{
		return *this;
	}
	int end = findDelimiterIndex(delim);
	String temp;
	if (end>0)
	{
		temp = left(end);
		remove(0);
	}
	else if (end == 0)
	{
		temp = " ";
		remove(0);
	}
	else
	{
		temp = move(*this);
	}
	
	return temp;
}
int String::findDelimiterIndex(const String& delim) const
{
	if (!delim)
	{
		return -1;
	}
	for (int i = 0; i < getLength(); i++) 
	{
		if (isDelimiter(data[i], delim)) 
		{
			return i;
		}
	}
	return -1;
}
