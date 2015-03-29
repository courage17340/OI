var
  a:array[0..100000] of 0..1;
  b,c,i,j,L,m,s:longint;
procedure work;
begin
  readln(L,m);
  fillchar(a,sizeof(a),0);
  for i:=0 to L do a[i]:=1;
  for i:=1 to m do
    begin
      readln(b,c);
      for j:=b to c do a[j]:=0;
    end;
  s:=0;
  for i:=0 to L do
    if a[i]=1 then s:=s+1;
  write(s);
end;

begin
  work;
end.