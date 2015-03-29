var
  opt:array[0..20001] of boolean;
  w:array[0..100] of longint;
  v,n,x,i,j:longint;
begin
  readln(v);
  readln(n);
  for i:=1 to n do readln(w[i]);
  fillchar(opt,sizeof(opt),false);
  opt[0]:=true;
  for i:=1 to n do
    for j:=v downto w[i] do
      if opt[j-w[i]] then opt[j]:=true;
  x:=v;
  while not opt[x] do dec(x);
  writeln(v-x);
end.