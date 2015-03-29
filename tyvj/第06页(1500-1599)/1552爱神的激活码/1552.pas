var
  a:array[1..91] of int64;
  b:array[1..91] of longint;
  i,j,n:longint;
  m:int64;
begin
  read(n,m);fillchar(b,sizeof(b),0);
  writeln(stderr,n,m);
  a[1]:=1;a[2]:=2;
  for i:=3 to 91 do a[i]:=int64(a[i-1]+a[i-2]);
  if m>a[n+1] then begin writeln('Cuperman is an unlucky man!');halt;end;
  m:=int64(m-int64(1));
  for i:=n downto 1 do
    if m>=a[i] then begin m:=int64(m-a[i]);b[i]:=1;end;
  for i:=n downto 1 do write(b[i]);
  writeln;
  readln;readln;
end.