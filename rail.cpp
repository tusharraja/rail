#include <bits/stdc++.h>
using namespace std;

string railFenceEncrypt(string &text)
{
  string row1, row2;
  string visual_row1, visual_row2;

  for (int i = 0; i < text.length(); i++)
  {
    if (i % 2 == 0)
    {
      row1.push_back(text[i]);
      visual_row1.push_back(text[i]);
      visual_row2.push_back(' ');
    }
    else
    {
      row2.push_back(text[i]);
      visual_row1.push_back(' ');
      visual_row2.push_back(text[i]);
    }
  }

  cout << "\n[Rail Fence Encryption Zig-Zag Pattern]\n";
  cout << visual_row1 << "\n"
       << visual_row2 << "\n";

  return row1 + row2;
}

string railFenceDecrypt(const string &cipher)
{
  int half = (cipher.length() + 1) / 2;
  string row1 = cipher.substr(0, half);
  string row2 = cipher.substr(half);

  cout << "\n[Rail Fence Decryption - Reconstructed Rows]\n";
  cout << "Row1: " << row1 << "\nRow2: " << row2 << "\n";

  string result;
  for (int i = 0; i < row1.length(); i++)
  {
    result.push_back(row1[i]);
    if (i < row2.length())
      result.push_back(row2[i]);
  }
  return result;
}

int main()
{
  while (true)
  {
    cout << "\n=== RAIL FENCE CIPHER (depth=2) ===\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "3. Quit\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter a number.\n";
      continue;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 3)
      break;

    string text;

    if (choice == 1)
    {
      cout << "Enter plaintext: ";
      getline(cin, text);
      string cipher = railFenceEncrypt(text);
      cout << "Ciphertext: " << cipher << "\n";
    }
    else if (choice == 2)
    {
      cout << "Enter ciphertext: ";
      getline(cin, text);
      string plain = railFenceDecrypt(text);
      cout << "Decrypted text: " << plain << "\n";
    }
    else
    {
      cout << "Invalid choice!\n";
    }
  }

  cout << "Exiting program.\n";
  return 0;
}
