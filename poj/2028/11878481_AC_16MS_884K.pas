var
  f:array[1..100] of longint;
  n,m,i,j,k,x,ans:longint;
begin
  while true do
    begin
      readln(n,m);
      if n=0 then break;
      fillchar(f,sizeof(f),0);
      for i:=1 to n do
        begin
          read(k);
          for j:=1 to k do
            begin
              read(x);
              inc(f[x]);
            end;
          readln;
        end;
      ans:=1;
      for i:=2 to 100 do
        if f[ans]<f[i] then ans:=i;
      if f[ans]>=m then writeln(ans) else writeln(0);
    end;
end.