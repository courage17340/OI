var
  a:array[0..2511,0..2511] of longint;
  i,j,m,n,p,q,x,y,min,node:longint;
  s:array[0..2511] of boolean;
begin
  fillchar(s,sizeof(s),false);
  read(n,m,x,y);
  s[x]:=true;
  fillchar(a,sizeof(a),1);
  for i:=1 to m do
    begin
      read(p,q);
      read(a[p,q]);a[q,p]:=a[p,q];
    end;
  for i:=2 to n do
    begin
      min:=maxlongint;
      node:=1;
      for j:=1 to n do
        if (a[x,j]<min)and(s[j]=false) then
          begin
            min:=a[x,j];node:=j;
          end;
      s[node]:=true;
      for j:=1 to n do
        if (a[x,node]+a[node,j]<a[x,j])and(s[j]=false) 
          then begin a[x,j]:=a[x,node]+a[node,j];a[j,x]:=a[x,j];end;
    end;
  writeln(a[x,y]);
end.