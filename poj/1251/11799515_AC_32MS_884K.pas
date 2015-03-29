var
  a:array[1..26,1..26] of longint;
  v:array[1..26] of boolean;
  n,i,j,ans,x,k,p,q:longint;
  ch,c1:char;
begin
  while true do
    begin
      fillchar(a,sizeof(a),255);
      fillchar(v,sizeof(v),false);
      readln(n);
      if n=0 then break;
      for i:=1 to n-1 do
        begin
          read(ch);
          read(k);
          for j:=1 to k do
            begin
              read(c1);
              while c1=' ' do read(c1);
              read(x);
              a[ord(ch)-64,ord(c1)-64]:=x;
              a[ord(c1)-64,ord(ch)-64]:=x;
            end;
          readln;
        end;
      ans:=maxlongint;
      p:=0;q:=0;
      for i:=1 to n-1 do
        for j:=i+1 to n do
          if (a[i,j]>-1)and(ans>a[i,j]) then
            begin
              p:=i;
              q:=j;
              ans:=a[i,j];
            end;
      v[p]:=true;
      v[q]:=true;
      for i:=1 to n-2 do
        begin
          p:=maxlongint;q:=0;
          for j:=1 to n do if v[j] then
            for k:=1 to n do if (not v[k])and(a[j,k]<>-1)and(p>a[j,k]) then
              begin
                p:=a[j,k];
                q:=k;
              end;
          ans:=ans+p;
          v[q]:=true;
        end;
      writeln(ans);
    end;
end.