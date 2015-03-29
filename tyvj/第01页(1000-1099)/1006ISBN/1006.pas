var
  a:array[1..9] of longint;
  s:string;
  x1,x:char;
  k,b,i:longint;
procedure init;
begin
  readln(s);
  x1:=s[13];
  k:=1;
  for i:=1 to 12 do
    if s[i]<>'-' then
      begin
        a[k]:=ord(s[i])-48;
        k:=k+1;
      end;
end;
procedure work;
begin
  b:=0;
  for i:=1 to 9 do
    b:=b+a[i]*i;
  b:=b mod 11;
  if b<10 then x:=chr(b+48)
          else x:='X';
  if x=x1 then write('Right')
          else
            begin
              for i:=1 to 12 do write(s[i]);
              write(x);
            end;
end;
begin
  init;
  work;
end.