var
  a:int64;
  i,j,n,k:longint;
  st:string;
begin
  readln(n,k);
  a:=1;
  for i:=1 to n do a:=a*i;
  str(a,st);
  while st[length(st)]='0' do delete(st,length(st),1);
  if length(st)<=k
    then write(st)
    else for i:=length(st)-k+1 to length(st) do write(st[i]);
  writeln;
end.