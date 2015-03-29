var
  a,b,c,d,e,f,g:longint;
  s:string;
function gcd(a,b:longint):longint;
begin
  if b=0 then exit(a);
  exit(gcd(b,a mod b));
end;
begin
  while not eof do
    begin
      readln(s);
      a:=ord(s[1])-48;
      b:=ord(s[3])-48;
      c:=ord(s[5])-48;
      d:=ord(s[7])-48;
      f:=b*d;
      if s[4]='-' then e:=a*d-b*c else e:=a*d+b*c;
      if e mod f=0 then begin writeln(e div f);continue;end;
      if e*f<0 then write('-');
      e:=abs(e);
      f:=abs(f);
      g:=gcd(e,f);
      e:=e div g;
      f:=f div g;
      writeln(e,'/',f);
    end;
end.