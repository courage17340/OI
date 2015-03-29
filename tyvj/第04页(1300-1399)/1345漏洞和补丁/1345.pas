var
  a,b:array[1..200] of ansistring;
  ans,n,m,i,j:longint;
begin
  readln(n,m);
  for i:=1 to n do
    begin
      readln(b[i]);
      for j:=1 to length(b[i]) do b[i,j]:=upcase(b[i,j]);
    end;
  for i:=1 to m do
    begin
      readln(a[i]);
      for j:=1 to length(a[i]) do a[i,j]:=upcase(a[i,j]);
    end;
  ans:=0;
  for i:=1 to n do
    for j:=1 to m do
      if (pos(b[i],a[j])>0)or(pos(a[j],b[i])>0) then begin inc(ans);break;end;
  writeln(ans);
end.