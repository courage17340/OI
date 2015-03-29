var
  a,b,q,t:qword;
  s,s1:ansistring;
  n,i,j,p:longint;
function acd(a,b:qword):qword;
begin
  if b=0 then exit(a);
  exit(acd(b,int64(a mod b)));
end;
begin
  readln(s);
  if s[1]='-' then begin write('-');delete(s,1,1);end;
  while s[1]='0' do delete(s,1,1);
  while s[length(s)]='0' do delete(s,length(s),1);
  s1:=s;
  if s='.' then begin writeln(0);halt;end;
  p:=pos('.',s);
  q:=0;
  for i:=1 to p-1 do
    begin
      q:=int64(q*10)+int64(ord(s[1])-48);
      delete(s,1,1);
    end;
  delete(s,1,1);
  if pos('(',s)=0 then
    begin
      a:=0;
      while length(s)>0 do
        begin
          a:=int64(a*int64(10)+int64(ord(s[1])-48));
          delete(s,1,1);
        end;
      b:=int64(1);
      while b<a do b:=int64(b*10);
      while (a mod 2=0)and(b mod 2=0) do begin a:=a div 2;b:=b div 2;end;
      while (a mod 5=0)and(b mod 5=0) do begin a:=a div 5;b:=b div 5;end;
      a:=int64(a+q*b);
      writeln(a,'/',b);
      readln;halt;
    end;
  if pos('(',s)=1 then
    begin
      delete(s,1,1);
      delete(s,length(s),1);
      b:=0;
      while length(s)>0 do
        begin
          a:=int64(a*int64(10)+int64(ord(s[1])-48));
          delete(s,1,1);
          b:=int64(b*int64(10)+int64(9));
        end;
      j:=acd(a,b);
      a:=a div j;b:=b div j;
      a:=int64(a+q*b);
      writeln(a,'/',b);
      readln;halt;
    end;
  s:=s1;t:=int64(1);
  while pos('(',s)-1<>pos('.',s) do
    begin
      p:=pos('.',s);
      s[p]:=s[p+1];
      s[p+1]:='.';
      t:=int64(t*10);
    end;
  p:=pos('.',s);
  q:=0;
  for i:=1 to p-1 do
    begin
      q:=int64(q*10)+int64(ord(s[1])-48);
      delete(s,1,1);
    end;
  delete(s,1,1);
  if pos('(',s)=1 then
    begin
      delete(s,1,1);
      delete(s,length(s),1);
      b:=0;
      while length(s)>0 do
        begin
          a:=int64(a*int64(10)+int64(ord(s[1])-48));
          delete(s,1,1);
          b:=int64(b*int64(10)+int64(9));
        end;
      j:=acd(a,b);
      a:=a div j;b:=b div j;
      a:=int64(a+q*b);
    end;
  b:=int64(b*t);
  while (a mod 2=0)and(b mod 2=0) do begin a:=a div 2;b:=b div 2;end;
  while (a mod 5=0)and(b mod 5=0) do begin a:=a div 5;b:=b div 5;end;
  writeln(a,'/',b);
  readln;readln;
end.