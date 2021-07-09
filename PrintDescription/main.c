//
//  main.c
//  PrintDescription
//
//  Created by Panayotis Matsinopoulos on 9/7/21.
//

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>

void describe255(CFTypeRef cfObject) {
  char buffer[256];
  CFIndex got;
  CFStringRef description = CFCopyDescription(cfObject);
  CFStringGetBytes(description,
                   CFRangeMake(0, CFStringGetLength(description)),
                   CFStringGetSystemEncoding(),
                   '?',
                   TRUE,
                   (UInt8 *)buffer,
                   255,
                   &got);
  buffer[got] = (char)0;
  printf("%s", buffer);
  CFRelease(description);
}

int main(int argc, const char * argv[]) {
  CFStringRef myObject = CFSTR("Hello World");
  
  describe255(myObject);
  
  CFRelease(myObject);
  
  return 0;
}
